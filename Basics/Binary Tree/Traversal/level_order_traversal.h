#ifndef LEVEL_ORDER_TRAVERSAL
#define LEVEL_ORDER_TRAVERSAL

#include <bits/stdc++.h>
#include "../Node.h"

using namespace std;

void levelOrderTraversal(Node *root)
{
  // check if root is empty or not
  if (!root)
  {
    cout << "tree is empty" << endl;
    return;
  }
  queue<Node *> q;
  q.push(root);

  cout << "Level order Traversal is " << endl;
  int level = 0;
  while (!q.empty())
  {
    int currSize = q.size();
    cout << "Level:" << level << "-> ";
    while (currSize--)
    {
      Node *currNode = q.front();
      q.pop();

      cout << currNode->data << " ";

      // get the left node
      if (currNode->left)
      {
        q.push(currNode->left);
      }

      // get the right child
      if (currNode->right)
      {
        q.push(currNode->right);
      }
    }
    level++;
    cout << endl;
  }
};

#endif