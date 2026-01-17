#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;
  Node(int data) : data(data), left(nullptr), right(nullptr) {};
};

void printTree(Node *root)
{
  queue<Node *> q;
  q.push(root);

  while (!q.empty())
  {
    int currSize = q.size();

    while (currSize > 0)
    {
      Node *currNode = q.front();
      cout << currNode->data << " , ";
      q.pop();

      // take the left node
      if (currNode->left != nullptr)
      {
        q.push(currNode->left);
      }

      // take the right node
      if (currNode->right != nullptr)
      {
        q.push(currNode->right);
      }
      currSize--;
    }
    cout << endl;
  }
}

int main()
{
  cout << "Enter the root Node" << endl;
  int rootValue;
  cin >> rootValue;
  Node *root = new Node(rootValue);
  queue<Node *> q;
  q.push(root);
  while (!q.empty())
  {
    Node *curr = q.front();
    q.pop();

    cout << "Enter the left child of " << curr->data << endl;
    int x;
    cin >> x;
    if (x != -1)
    {
      Node *leftNode = new Node(x);
      curr->left = leftNode;
      q.push(leftNode);
    }

    cout << "Enter the right child of " << curr->data << endl;
    int y;
    cin >> y;
    if (y != -1)
    {
      Node *rightNode = new Node(y);
      curr->right = rightNode;
      q.push(rightNode);
    }
  }

  printTree(root);
}