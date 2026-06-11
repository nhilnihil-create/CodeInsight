#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef pair<int,ll> p;
typedef pair<pii,int> P;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e18;
const ll MOD=1e9+7;
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(){
    int n,k;cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    bool ok=false;
    int g=a[0];
    for(int i=0;i<n;++i) g=gcd(g,a[i]);
    for(int i=0;i<n;++i){
        if(k>a[i]) continue;
        if((a[i]-k)%g==0){
            cout<<"POSSIBLE"<<endl;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}