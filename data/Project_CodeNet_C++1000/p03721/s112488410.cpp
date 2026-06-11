


#include <bits/stdc++.h>
#include <string.h>
#include <vector>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
#define r0 return 0
#define INF (int)1e15
#define MOD 1000000007

#define access(i) a[i/3][i%3]
//#define random_shuffle(r...)random_shuffle(r,[](int _){return my_rand()%_;})



 int main(){

 ll n,k;
   cin>>n>>k;

   map<ll,ll>mp;

   for(int i=0;i<n;++i){
      int a,b;
      cin>>a>>b;
      mp[a] += b;
   }

   ll cnt=0;

   map<ll,ll>::iterator it;
   for(it=mp.begin();it!=mp.end();it++){
      cnt += it->second;
      if(cnt >=  k){
            cout<<it->first<<endl;
            return 0;
      }
   }

 return 0;
 }
