//#pragma GCC target ("1avx2")
#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pb push_back 
const int M=10000000000;
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

signed main()
{
  fastio;
  int t=1;
  //cin>>t;
  while(t--)
  {
   int a,b;
   char op;
   cin>>a>>op>>b;
   if(op=='+')
    cout<<a+b;
   else 
    cout<<a-b;
  }
  return 0;
}
