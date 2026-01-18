#include "./create.h"

using namespace std;

void findLeftMostIndex(Node *root, int index, int &rightMostIndex)
{

  if (!root)
    return;

  rightMostIndex = max(rightMostIndex, index);

  findLeftMostIndex(root->left, index - 1, rightMostIndex);
  findLeftMostIndex(root->right, index + 1, rightMostIndex);
}

int main()
{
  Node *root = create();
  printLevelOrder(root);

  int rightMostIndex = 0;

  cout << endl
       << endl;
  findLeftMostIndex(root, 0, rightMostIndex);
  cout << "right Most Index is : " << rightMostIndex << endl;
}
