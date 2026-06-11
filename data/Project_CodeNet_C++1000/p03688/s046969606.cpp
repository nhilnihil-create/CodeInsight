#include<bits/stdc++.h>
#define rep(i,k,n) for(int i =k;i<n;i++)
using namespace std;
int main()
{
  int n,m,M;
  cin >> n;
  vector<int>a(n);
  rep(i,0,n)
  {
    cin >> a[i];
  }
  m=*std::min_element(a.begin(),a.end());
  M=*std::max_element(a.begin(),a.end());
  
  if(M-m>1)
  {
    cout << "No" << endl;
  }
  else
  {
    int c=0;
    rep(i,0,n)
    {
      if(a[i]==m)
      {
        ++c;
      }
    }
   
    if(M==m)
    {
      if(m==n-1||m<=n/2)
      {
        cout << "Yes" << endl;
      }
      else
      {
        cout << "No" << endl;
      }
    }
    else
    {
      if(M>c&&(n-c)/2>=M-c)
      {
        cout << "Yes" << endl;
      }
      else
      {
        cout << "No" << endl;
      }
    }
  }
  
}
