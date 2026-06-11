#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  
  int max = 1;
  int count = 0,maxcount = 0;
  for(int i = 1; i <= N; i++){
      int j = i;
      while( (j % 2) == 0){
        count++;
        j /= 2;
      }
      if(count > maxcount){
        maxcount = count;
        max = i;
      }
      count = 0;
  }
  cout << max << endl;
}
