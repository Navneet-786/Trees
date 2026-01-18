#ifndef DELETE_NODE
#define DELETE_NODE

#include "../node.h"
#include <bits/stdc++.h>
using namespace std;

Node *deleteNode(Node *root, int ele)
{ // traverse and try to find the ele
  if (!root)
    return nullptr;

  if (ele < root->data)
  {
    root->left = deleteNode(root->left, ele);
  }
  else if (ele > root->data)
  {
    root->right = deleteNode(root->right, ele);
  }
  else
  {
    // we get the element
    //   if ele is root node
    if (!root->left && !root->right)
    {
      delete root;
      return nullptr;
    }
    // if only left child exist
    else if (!root->right)
    {
      Node *temp = root->left;
      delete root;
      return temp;
    }
    else if (!root->left)
    {
      Node *temp = root->right;
      delete root;
      return temp;
    }
    else
    {
      // if both child present
      // we have to find either inorder precessor or inorder successor
      // so here i am going to find inorder precesor (node which is just smaller than currNode)
      Node *nextNode = root->left;
      Node *prevNode = nullptr;

      // move as much as possibe to right of left subtree
      while (nextNode->right != nullptr)
      {
        prevNode = nextNode;
        nextNode = nextNode->right;
      }

      if (prevNode)
      {
        root->data = nextNode->data;
        prevNode->right = nextNode->left;
        delete nextNode;
      }
      else
      {
        // it means there is no right subtree of left node of root
        root->data = nextNode->data;
        root->left = nextNode->left;
        delete nextNode;
      }
    }
  }

  return root;
}

#endif