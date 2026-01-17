#ifndef ITERATIVE_POSTORDER
#define ITERATIVE_POSTORDER

#include <bits/stdc++.h>
#include "../node.h"

using namespace std;

void postorderIterative(Node *root)
{
  if (!root)
  {
    cout << "tree is empty" << endl;
    return;
  }
  stack<int> ans;
  stack<Node *> st;
  st.push(root);

  while (!st.empty())
  {
    Node *currNode = st.top();
    st.pop();
    ans.push(currNode->data);

    if (currNode->left)
    {
      st.push(currNode->left);
    }
    if (currNode->right)
    {
      st.push(currNode->right);
    }
  }
  cout << endl
       << "--------------------------" << endl;
  cout << "iterative post order traversal" << endl;
  while (!ans.empty())
  {
    cout << ans.top() << " ";
    ans.pop();
  }

  cout << endl
       << "--------------------------" << endl;
}

#endif