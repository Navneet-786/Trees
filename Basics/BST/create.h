#ifndef CREATE_BST
#define CREATE_BST

#include <vector>
#include "../node.h"

Node *placeAtCorrectPos(Node *root, int ele)
{
  if (!root)
  {
    return new Node(ele);
  }

  if (ele < root->data)
  {
    root->left = placeAtCorrectPos(root->left, ele);
  }
  else
  {
    root->right = placeAtCorrectPos(root->right, ele);
  }
  return root;
}

Node *createBST(std::vector<int> &vec)
{
  if (vec.size() == 0)
  {
    return nullptr;
  }

  Node *root = new Node(vec[0]);
  for (int i = 1; i < vec.size(); i++)
  {
    placeAtCorrectPos(root, vec[i]);
  }

  return root;
}

#endif