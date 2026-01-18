#ifndef CREATE_BINARY_TREE
#define CREATE_BINARY_TREE

#include <iostream>
#include <queue>
#include "Traversal/level_order_traversal.h"
#include "Traversal/pre_order_traversal.h"
#include "Traversal/inorder_traversal.h"
#include "Traversal/postorder_traversal.h"
#include "Traversal/pre_order_iterative.h"
#include "Traversal/inorder_iterative.h"
#include "Traversal/post_order_iterative.h"
#include "node.h"

// recursion
inline void printWithPreOrder(Node *root)
{
  preOrderTraversal(root);
}

inline void printWithInOrder(Node *root)
{
  inorderTraversal(root);
}

inline void printWithPostOrder(Node *root)
{
  postOrderTraversal(root);
}

// BFS
inline void printLevelOrder(Node *root)
{
  levelOrderTraversal(root);
}

// iterative
inline void printWithPreOrderIterative(Node *root)
{
  preOrderIterative(root);
}

inline void printWithInOrderIterative(Node *root)
{
  inorderIterative(root);
}

inline void printWithPostOrderIterative(Node *root)
{
  postorderIterative(root);
}

inline Node *create()
{
  std::cout << "Enter the root Node\n";
  int rootValue;
  std::cin >> rootValue;

  Node *root = new Node(rootValue);
  std::queue<Node *> q;
  q.push(root);

  while (!q.empty())
  {
    Node *curr = q.front();
    q.pop();

    std::cout << "Enter the left child of " << curr->data << "\n";
    int x;
    std::cin >> x;
    if (x != -1)
    {
      curr->left = new Node(x);
      q.push(curr->left);
    }

    std::cout << "Enter the right child of " << curr->data << "\n";
    int y;
    std::cin >> y;
    if (y != -1)
    {
      curr->right = new Node(y);
      q.push(curr->right);
    }
  }

  return root;
}

#endif
