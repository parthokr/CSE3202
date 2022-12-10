#include <iostream>
#include <iterator>
#include <sys/types.h>
#include <unistd.h>
using namespace std;
int k = 1;
void tree(int n) { // Creates a process tree
  if (n == 0)
    return; // We have reached a leaf, so we leave.

  int rchild = fork(); // create right child
  wait(0);
  cout << "Child " << getpid() << " parent: " << getppid() << endl;
  if (rchild != 0) {     // we are the parent
    int lchild = fork(); // create left child
    wait(0);
    cout << "Child " << getpid() << " parent: " << getppid() << endl;

    if (lchild == 0)
      tree(n - 1); // we are the left child, so we create the left subtreee
  } else {         // we are the right child
    tree(n - 1);   // create the right subtree
  }
}
int main() { tree(2); }
