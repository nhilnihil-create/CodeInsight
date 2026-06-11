#include<bits/stdc++.h>
using namespace std;

#define int long long int 

int32_t main()
{

  int n,m;
  cin>>n>>m;
  vector<string> A,B;
  for(int i=0;i<n;i++)
  {
    string str;
    cin>>str;
    A.push_back(str);
  }
  for(int i=0;i<m;i++)
  {
    
      string str;
      cin>>str;
       B.push_back(str);
    
  }

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if((i+m-1)>= n || (j+m-1)>=n)
      continue;
      int match=true;
      for(int p=0;p<m;p++)
      {
        for(int k=0;k<m;k++)
        {
          if(A[i+p][j+k]!=B[p][k])match=false;
        }
      }
      if(match)
      {cout<<"Yes"<<endl;return 0;}

    }
  }
  cout<<"No"<<endl;
}