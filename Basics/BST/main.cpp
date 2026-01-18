#include "create.h"
#include "printBST.h"
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
}