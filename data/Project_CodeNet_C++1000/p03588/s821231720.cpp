#include <bits/stdc++.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define rep2(i,k,n) for(int i=k;i<=n;i++)
typedef long long ll;
using namespace std;
int main()
{
   int N;
   cin >> N;
   vector<pair<int,int>>P(N);
   rep(i,0,N){
       cin >> P[i].first >> P[i].second;
   }

   sort(P.begin(),P.end(),greater<pair<int,int>>());
   
   cout << P[0].first+P[0].second << endl;
   return 0;
}