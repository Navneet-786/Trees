#ifndef PRINT_BST
#define PRINT_BST
#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include "../node.h"

// inorder Traversal -> sorted vec
void print(Node *root)
{
  std::stack<std::pair<Node *, int>> st;
  st.push({root, 0});
  while (!st.empty())
  {
    Node *currNode = st.top().first;
    int count = st.top().second;
    st.pop();

    if (count == 1)
    {
      std::cout << currNode->data << " ";
      continue;
    }

    if (currNode->right)
    {
      st.push({currNode->right, 0});
    }

    st.push({currNode, 1});

    if (currNode->left)
    {
      st.push({currNode->left, 0});
    }
  }
}

#endif