#include <iostream>
#include <deque>
#include <string>

using namespace std;

#define LEFT false
#define RIGHT true

int main()	{
  long long n;
  cin >> n;
  long long a[n] = {0};
  for (int i = 0; i < n; i++)	{
    cin >> a[i];
  }
  deque<long long> b;
  bool insert;
  if (n % 2 == 0)	{
    //start insert from left
    insert = LEFT;
  }
  else {
    insert = RIGHT;
  }
  b.push_back(a[0]);
  for (long long i = 1; i < n; i++)	{
    if (insert == RIGHT)	{
      b.push_back(a[i]);
    }
    else	{
      b.push_front(a[i]);
    }
    insert = !insert;
  }
  for (long long i = 0; i < n; i++)	{
    cout << b[i] << " ";
  }
  cout << endl;
  return 0;
}