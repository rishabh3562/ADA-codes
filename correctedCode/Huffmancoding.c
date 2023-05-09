#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
// Node structure for Huffman tree
typedef struct Node
{
  char character;
  int frequency;
  struct Node *left;
  struct Node *right;
} Node;

// Function to create a new node
Node *createNode(char character, int frequency)
{
  Node *node = (Node *)malloc(sizeof(Node));
  node->character = character;
  node->frequency = frequency;
  node->left = node->right = NULL;
  return node;
}

// Function to build Huffman tree
Node *buildHuffmanTree(char data[], int freq[], int size)
{
  Node **nodes = (Node **)malloc(size * sizeof(Node *));

  for (int i = 0; i < size; i++)
  {
    nodes[i] = createNode(data[i], freq[i]);
  }

  int n = size;
  while (n > 1)
  {
    int i, j;
    int min1 = INT_MAX, min2 = INT_MAX;
    for (i = 0; i < n; i++)
    {
      if (nodes[i]->frequency < min1)
      {
        min2 = min1;
        min1 = nodes[i]->frequency;
        j = i;
      }
      else if (nodes[i]->frequency < min2)
      {
        min2 = nodes[i]->frequency;
      }
    }

    Node *mergedNode = createNode('$', min1 + min2);
    mergedNode->left = nodes[j];
    mergedNode->right = nodes[n - 1];

    nodes[j] = mergedNode;
    n--;
  }

  Node *root = nodes[0];
  free(nodes);
  return root;
}

// Function to print Huffman codes
void printHuffmanCodesHelper(Node *root, char code[], int top)
{
  if (root->left)
  {
    code[top] = '0';
    printHuffmanCodesHelper(root->left, code, top + 1);
  }

  if (root->right)
  {
    code[top] = '1';
    printHuffmanCodesHelper(root->right, code, top + 1);
  }

  if (!root->left && !root->right)
  {
    code[top] = '\0';
    printf("%c: %s\n", root->character, code);
  }
}

void printHuffmanCodes(Node *root)
{
  char code[100];
  printHuffmanCodesHelper(root, code, 0);
}

int main()
{
  char data[] = {'a', 'b', 'c', 'd', 'e'};
  int freq[] = {5, 9, 12, 13, 16};
  int size = sizeof(data) / sizeof(data[0]);

  Node *root = buildHuffmanTree(data, freq, size);

  printf("Huffman Codes:\n");
  printHuffmanCodes(root);

  return 0;
}

// Output:-
/*
Huffman Codes:
a: 00
e: 01
b: 10
d: 11


*/

// $$$$$$$$$$$$$$$$$$$$$$ RISHABh ka code $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define MAX_TREE_HT 100

// struct MinHeapNode {
//   char data;
//   unsigned freq;
//   struct MinHeapNode *left, *right;
// };

// struct MinHeap {
//   unsigned size;
//   unsigned capacity;
//   struct MinHeapNode **array;
// };

// struct MinHeapNode *newNode(char data, unsigned freq) {
//   struct MinHeapNode *temp = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
//   temp->left = temp->right = NULL;
//   temp->data = data;
//   temp->freq = freq;
//   return temp;
// }

// struct MinHeap *createMinHeap(unsigned capacity) {
//   struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
//   minHeap->size = 0;
//   minHeap->capacity = capacity;
//   minHeap->array = (struct MinHeapNode **)malloc(minHeap->capacity * sizeof(struct MinHeapNode *));
//   return minHeap;
// }

// void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b) {
//   struct MinHeapNode *t = *a;
//   *a = *b;
//   *b = t;
// }

// void minHeapify(struct MinHeap *minHeap, int idx) {
//   int smallest = idx;
//   int left = 2 * idx + 1;
//   int right = 2 * idx + 2;
//   if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
//     smallest = left;
//   if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
//     smallest = right;
//   if (smallest != idx) {
//     swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
//     minHeapify(minHeap, smallest);
//   }
// }

// int isSizeOne(struct MinHeap *minHeap) {
//   return (minHeap->size == 1);
// }

// struct MinHeapNode *extractMin(struct MinHeap *minHeap) {
//   struct MinHeapNode *temp = minHeap->array[minHeap->size - 1];
//   minHeap->array[minHeap->size - 1] = temp;
//   --minHeap->size;
//   minHeapify(minHeap, 0);
//   return temp;
// }

// void insertMinHeap(struct MinHeap *minHeap, struct MinHeapNode *minHeapNode) {
//   ++minHeap->size;
//   int i = minHeap->size - 1;
//   while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
//     minHeap->array[i] = minHeap->array[(i - 1) / 2];
//     i = (i - 1) / 2;
//   }
//   minHeap->array[i] = minHeapNode;
// }

// void buildMinHeap(struct MinHeap *minHeap) {
//   int n = minHeap->size - 1;
//   int i;
//   for (i = (n - 1) / 2; i >= 0; --i)
//     minHeapify(minHeap, i);
// }

// void printArr(int arr[], int n) {
//   int i;
//   for (i = 0; i < n; ++i)
//     printf("%d", arr[i]);
//   printf("\n");
// }

// int isLeaf(struct MinHeapNode *root) {
//   return !(root->left) && !(root->right);
// }

// struct MinHeap *createAndBuildMinHeap(char data[], int freq[], int size) {
//   struct MinHeap *minHeap = createMinHeap(size);
//   for (int i = 0; i < size; ++i)
//     minHeap->array[i] = newNode(data[i], freq[i]);
//   minHeap->size = size;
//   buildMinHeap(minHeap);
//   return minHeap;
// }

// struct MinHeapNode *buildHuffmanTree(char data[], int freq[], int size) {
//   struct MinHeapNode *left, *right, *top;
//   struct MinHeap *minHeap = createAndBuildMinHeap(data, freq, size);
//   while (!isSizeOne(minHeap)) {
//     left = extractMin(minHeap);
//     right = extractMin(minHeap);
//     top = newNode('$', left->freq + right->freq);
//     top->left = left;
//     top->right = right;
//     insertMinHeap(minHeap, top);
//   }
//   return extractMin(minHeap);
// }

// //   Once the Huffman tree is built, we can traverse it to generate the Huffman codes for each character. Here's an example implementation of Huffman coding in C that includes the code generation step:

// // ```c
// void printCodes(struct MinHeapNode *root, int arr[], int top) {
//   if (root->left) {
//     arr[top] = 0;
//     printCodes(root->left, arr, top + 1);
//   }
//   if (root->right) {
//     arr[top] = 1;
//     printCodes(root->right, arr, top + 1);
//   }
//   if (isLeaf(root)) {
//     printf("%c: ", root->data);
//     printArr(arr, top);
//   }
// }

// void HuffmanCodes(char data[], int freq[], int size) {
//   struct MinHeapNode *root = buildHuffmanTree(data, freq, size);
//   int arr[MAX_TREE_HT], top = 0;
//   printCodes(root, arr, top);
// }

// int main() {
//   char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
//   int freq[] = {45, 13, 12, 16, 9, 5};
//   int size = sizeof(data) / sizeof(data);
//   HuffmanCodes(data, freq, size);
//   return 0;
// }