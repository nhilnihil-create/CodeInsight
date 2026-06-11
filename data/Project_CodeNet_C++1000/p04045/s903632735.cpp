#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  int n, k; cin >> n >> k;
  int data;
  vector <bool> flag(10, true);
  bool key = true;
  for(int i = 0; i < k; i++)
  {
      cin >> data;
      flag[data] = false;
  }
  int temp;
  int answer = n;
  while(key)
  {
    temp = answer;
    while((flag[temp%10] != false) && (temp != 0))
    {
      temp/=10;
      if(temp == 0)
      {
        key = false;
      }
    }
    answer++;
  }
    answer--;
  cout << answer << endl;
}