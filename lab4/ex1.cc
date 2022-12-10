#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <vector>

using namespace std;
int main() {
  int size = 5;
  vector<int> v(size);
  for (int &i : v)
    cin >> i;
  pid_t f = fork();
  if (f == 0) {
    cout << "I am child process having id: " << getpid() << endl;
    cout << "My parent has id: " << getppid() << endl;
    cout << "My task is to calculate sum of odd numbers" << endl;
    int sum = 0;
    for (int i = 1; i < size; i += 2)
      sum += v[i];
    cout << "Sum: " << sum << endl;
    sleep(10);
  } else {
    wait(0);
    cout << "I am parent process having id: " << getpid() << endl;
    cout << "My child has id: " << f << endl;
    cout << "My task is to calculate sum of even numbers" << endl;
    int sum = 0;
    for (int i = 0; i < size; i += 2)
      sum += v[i];
    cout << "Sum: " << sum << endl;
  }
}
