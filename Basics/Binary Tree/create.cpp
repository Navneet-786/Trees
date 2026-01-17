
#include "Traversal/level_order_traversal.h"
#include "Traversal/pre_order_traversal.h"
#include "Traversal/inorder_traversal.h"
#include "Traversal/postorder_traversal.h"
#include "node.h"
using namespace std;

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

  // level order trevsersl
  levelOrderTraversal(root);
  cout << endl;
  cout << "poreOrder traversal : " << endl;
  preOrderTraversal(root);

  cout << endl;
  cout << "Inorder traversal : " << endl;
  inorderTraversal(root);

  cout << endl;
  cout << "postorder traversal : " << endl;
  postOrderTraversal(root);
}