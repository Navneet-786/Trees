#include "create.h"
#include "printBST.h"
#include "deleteNode.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "ENter the number of elements" << endl;
  cin >> n;

  vector<int> vec;
  cout << "ENter the elements" << endl;
  while (n--)
  {
    int x;
    cin >> x;
    vec.push_back(x);
  }

  Node *root = createBST(vec);
  print(root);

  cout << "wanna delete any element\n1->yes\n0->No" << endl;
  bool res;
  cin >> res;
  if (!res)
  {
    cout << "No element deleted" << endl;
    return 0;
  }
  int ele;
  cout << "Enter the node that you wanna delete" << endl;
  cin >> ele;

  deleteNode(root, ele);

  cout << "new tree will be: " << endl;
  print(root);
}