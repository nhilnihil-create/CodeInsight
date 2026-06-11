#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define ld  double
#define ll long long
#define int long long


using namespace std;

const int MAXN = 301 * 1001  , MOD = 1e9 + 7 , sq = 333  ;


int32_t main()
{
   ios::sync_with_stdio(0);cin.tie(0);

   int n ;
   cin >> n ;
   deque < int > dq ;

   int s = 0 , i = 1  ;
   while(s<n)
     dq.push_back(i),s+=i,i++ ;
   while(s>n)
   {
       if(dq.front()==1)
        dq.pop_front() ;
       else
        dq[0]--;
       s--;
   }
   for(auto u : dq)
    cout<<u<<'\n';



}
