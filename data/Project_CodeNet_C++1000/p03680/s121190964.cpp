#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<vector<int>> a(N+1, vector<int>(2));
  int flag = 0;
  int i = 1;
  int count = 1;
  
  for(int i=1; i<N+1; i++)
  {
    cin >> a.at(i).at(0);
    a.at(i).at(1) = 0; //non-visited
  }
  
  do
  {
    if(a.at(i).at(0) == 2)
    {
      flag = 1;
      break;
    }
    else if(a.at(i).at(1) == 1) //すでに訪れましたよ
    {
      break;
    }
    a.at(i).at(1) = 1;
    count++;
    i = a.at(i).at(0);
  }while(a.at(i).at(0) != 1);
  
  if(flag == 0) cout << -1 << endl;
  else cout << count << endl;
}
    
  