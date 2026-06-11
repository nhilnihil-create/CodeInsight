

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

 int main(){

  long long n,k;
  cin>>n>>k;

 vector<pair<ll,ll>> p(n);

 for(int i=0;i<n;i++){
    cin>>p[i].first>>p[i].second;
 }

 sort(p.begin(),p.end());

 ll sum =0 ;

 for(int i=0;i<n;i++)
 {
    sum += p[i].second;
    if(sum >= k){
        cout<<p[i].first<<endl;
        return 0;
    }

 }

 return 0;
 }
