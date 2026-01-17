#ifndef NODE
#define NODE

class Node
{
public:
  int data;
  Node *left;
  Node *right;
  Node(int data) : data(data), left(nullptr), right(nullptr) {};
};

#endif