#ifndef POSTORDER
#define POSTORDER

#include <bits/stdc++.h>
#include "../node.h"

using namespace std;

void postOrderTraversal(Node *root)
{
  if (!root)
    return;

  postOrderTraversal(root->left);
  postOrderTraversal(root->right);
  cout << root->data << " ";
}
#endif