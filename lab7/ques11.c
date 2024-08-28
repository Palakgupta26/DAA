#include <stdio.h>
#include <stdlib.h>

// Define a structure for a Huffman tree node
struct Node {
    char character;
    double probability;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;

// Function to create a new node
Node* createNode(char character, double probability) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->character = character;
    newNode->probability = probability;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build the Huffman tree
Node* buildHuffmanTree(Node* nodes[], int n) {
    while (n > 1) {
        // Find the two nodes with the lowest probabilities
        int min1 = 0;
        int min2 = 1;
        if (nodes[min1]->probability > nodes[min2]->probability) {
            int temp = min1;
            min1 = min2;
            min2 = temp;
        }
        for (int i = 2; i < n; i++) {
            if (nodes[i]->probability < nodes[min1]->probability) {
                min2 = min1;
                min1 = i;
            } else if (nodes[i]->probability < nodes[min2]->probability) {
                min2 = i;
            }
        }

        // Create a new node with combined probability
        Node* combinedNode = createNode('\0', nodes[min1]->probability + nodes[min2]->probability);
        combinedNode->left = nodes[min1];
        combinedNode->right = nodes[min2];

        // Remove the used nodes and add the combined node
        nodes[min1] = combinedNode;
        nodes[min2] = nodes[n - 1];
        n--;
    }

    return nodes[0]; // The root of the Huffman tree
}

// Function to print Huffman codes
void printHuffmanCodes(Node* root, int code[], int top) {
    if (root->left) {
        code[top] = 0;
        printHuffmanCodes(root->left, code, top + 1);
    }
    if (root->right) {
        code[top] = 1;
        printHuffmanCodes(root->right, code, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->character);
        for (int i = 0; i < top; i++) {
            printf("%d", code[i]);
        }
        printf("\n");
    }
}

int main() {
    // Define the number of characters
    int n = 10;

    // Prompt the user to enter characters and their probabilities
    char characters[n];
    double probabilities[n];

    printf("Enter 10 characters and their probabilities:\n");
    for (int i = 0; i < n; i++) {
        scanf(" %c %lf", &characters[i], &probabilities[i]);
    }

    // Create an array of nodes
    Node* nodes[n];
    for (int i = 0; i < n; i++) {
        nodes[i] = createNode(characters[i], probabilities[i]);
    }

    // Build the Huffman tree
    Node* root = buildHuffmanTree(nodes, n);

    // Print Huffman codes
    int code[n];
    int top = 0;
    printf("Huffman Codes:\n");
    printHuffmanCodes(root, code, top);

    return 0;
}
