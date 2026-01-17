#ifndef INORDER
#define INORDER

#include <bits/stdc++.h>
#include "../node.h"

using namespace std;

void inorderTraversal(Node *root)
{
  if (!root)
    return;

  inorderTraversal(root->left);
  cout << root->data << " ";
  inorderTraversal(root->right);
}

#endif