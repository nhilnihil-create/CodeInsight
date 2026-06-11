#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define eb emplace_back
#define precision(n) cout << fixed << setprecision(n);
#define fast {ios_base::sync_with_stdio(false);cin.tie(NULL);}
int main()
{
    fast;
   int a[10001];
  for(int i=0;i<3;i++)
  {
      cin>>a[i];
  }
  sort(a,a+3);
  int cnt=1;
  for(int i=0;i<2;i++)
  {
      if(a[i]!=a[i+1])
      {
          cnt++;
      }
  }
  cout<<cnt<<endl;
    return 0;
}
