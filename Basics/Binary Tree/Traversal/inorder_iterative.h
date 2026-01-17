#ifndef INORDER_ITERATIVE
#define INORDER_ITERATIVE

#include <bits/stdc++.h>
#include "../node.h"
using namespace std;

void inorderIterative(Node *root)
{
  if (!root)
  {
    cout << "Empty tree" << endl;
    return;
  }

  cout << endl
       << "--------------------------------------" << endl;
  cout << "Iterative Inorder traversal" << endl;
  stack<pair<Node *, int>> st;
  st.push({root, 0});

  while (!st.empty())
  {
    Node *currNode = st.top().first;
    int count = st.top().second;

    st.pop();

    if (count == 1)
    {
      cout << currNode->data << " ";
      continue;
    }

    // take the right node
    if (currNode->right)
    {
      st.push({currNode->right, 0});
    }

    // take the currNode
    st.push({currNode, 1});

    // take the left Node
    if (currNode->left)
    {
      st.push({currNode->left, 0});
    }
  }
  cout << endl
       << "--------------------------------------" << endl
       << endl;
}
#endif