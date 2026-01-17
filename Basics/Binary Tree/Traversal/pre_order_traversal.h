#ifndef PREORDER
#define PREORDER

#include <bits/stdc++.h>
#include "../node.h"
using namespace std;

void preOrderTraversal(Node *root)
{
  if (!root)
    return;

  cout << root->data << " ";
  preOrderTraversal(root->left);
  preOrderTraversal(root->right);
}

#endif