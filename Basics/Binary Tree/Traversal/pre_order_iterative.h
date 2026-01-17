#ifndef PREORDER_ITERATIVE
#define PREORDER_ITERATIVE

#include <bits/stdc++.h>
#include "../node.h"

using namespace std;

void preOrderIterative(Node *root)
{
  if (!root)
  {
    cout << "Tree is empty" << endl;
  }

  stack<Node *> st;
  st.push(root);
  cout << "-----------------------------------" << endl;
  cout << "Iterative PreOrder Traversal" << endl;

  while (!st.empty())
  {
    Node *currNode = st.top();
    st.pop();

    cout << currNode->data << " ";

    if (currNode->right)
    {
      st.push(currNode->right);
    }
    if (currNode->left)
    {
      st.push(currNode->left);
    }
  }

  cout << endl
       << "-----------------------------------" << endl
       << endl;
}
#endif