#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define ld  double
#define ll long long
#define int long long


using namespace std;

const int MAXN = 301 * 1001  , MOD = 1e9 + 7 , sq = 333  ;


string s[30] ;

int32_t main()
{
   ios::sync_with_stdio(0);cin.tie(0);
   int n, m ;
   cin >> n >> m ;
   for(int i = 0 ; i < n ; i ++ )
   {
       string s;
       for(int j = 0 ; j < m ; j ++ )
       {
           cin >> s ;
           if(s=="snuke")
        {
             cout<<(char)(j+'A')<<i+1;

        }
       }
   }


}
