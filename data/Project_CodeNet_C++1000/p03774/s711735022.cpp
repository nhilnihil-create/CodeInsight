#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
int main(){
    ll n,m;
    cin >> n>>m;
    vector<pair<ll,ll>> student(n);
    vector<pair<ll,ll>> check(m);
    rep(i,0,n){
        cin >> student[i].first;
        cin >> student[i].second;
    }
    rep(i,0,m){
        cin>>check[i].first;
        cin>>check[i].second;
    }
    vector<int> ans(n);
    //cout<<check[0].first<<endl;
    rep(i,0,n){
        ll k = 1000000000;
        rep(j,0,m){
            ll now = abs(student[i].first-check[j].first)+abs(student[i].second-check[j].second);
            if(now<k){
                k = now;
                ans[i]=j;
                
            }
        }
    }
    rep(i,0,n){
        cout<<ans[i]+1<<endl;
    }
  return 0;
}