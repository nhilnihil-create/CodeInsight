#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 100005
#define INF 1000000005
#define PI 3.1415926535897
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
#define SZ(x) int(x.size())
#define IN(a) cin>>(a)
#define OUT(a) cout<<(a)<<endl
typedef pair<int,int> P;
const int MAX = 1000005;
const int MOD = 1000000007;
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    REP(i,n)cin>>a[i];
    ll ans=0;
    map<int,P>m;
    REP(i,n){
        m[a[i]].first=i%2;
    }
    sort(ALL(a));
    REP(i,n){
        m[a[i]].second=i%2;
    }
    for(auto p:m){
        if(p.second.first!=p.second.second)ans++;
    }
    ans/=2;
    OUT(ans);
}