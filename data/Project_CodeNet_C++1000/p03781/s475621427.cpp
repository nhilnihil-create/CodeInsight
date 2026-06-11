#include<bits/stdc++.h>
using namespace std;

int main()
{
  int x;
  cin >> x;
  int time = 0;
  int length = 0;
  while(length < x)
  {
    time++;
    length += time;
  }
  cout << time << endl;
}