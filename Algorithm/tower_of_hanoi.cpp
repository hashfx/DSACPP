#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {
  int disk;
  char from_rod;
  char to_rod;
  char aux_rod;
  Node* left;
  Node* right;

  Node(int disk, char from_rod, char to_rod, char aux_rod) :
    disk(disk), from_rod(from_rod), to_rod(to_rod), aux_rod(aux_rod), left(nullptr), right(nullptr) {}
};

void printNode(Node* node) {
  if (node == nullptr) {
    return;
  }
  cout << "Move disk " << node->disk << " from " << node->from_rod << " to " << node->to_rod << endl;
  printNode(node->left);
  printNode(node->right);
}

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod, Node*& root) {
  if (n == 0) {
    return;
  }
  root = new Node(n, from_rod, to_rod, aux_rod);

  towerOfHanoi(n - 1, from_rod, aux_rod, to_rod, root->left);
  towerOfHanoi(n - 1, aux_rod, to_rod, from_rod, root->right);
}

int main() {
  int num_disks;
  cout << "Enter the number of disks: ";
  cin >> num_disks;

  Node* root = nullptr;
  towerOfHanoi(num_disks, 'A', 'C', 'B', root);

  cout << "Moves to solve the Tower of Hanoi puzzle (represented as a tree):" << endl;
  printNode(root);

  return 0;
}
