#include "./create.h"

using namespace std;

void findLeftMostIndex(Node *root, int index, int &leftMostIndex)
{

  if (!root)
    return;

  leftMostIndex = min(leftMostIndex, index);

  findLeftMostIndex(root->left, index - 1, leftMostIndex);
  findLeftMostIndex(root->right, index + 1, leftMostIndex);
}

int main()
{
  Node *root = create();
  printLevelOrder(root);

  int leftMostIndex = 0;

  cout << endl
       << endl;
  findLeftMostIndex(root, 0, leftMostIndex);
  cout << "Left Most Index is : " << leftMostIndex << endl;
}
