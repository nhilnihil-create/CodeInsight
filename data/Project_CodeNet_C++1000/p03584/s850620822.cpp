#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n=100005;
typedef pair<int,int> P;
#define fi first
#define se second
int n,k;
P p[max_n];
ll solve(vector<P> v,int bit){
    if(bit==-1){
        ll res=0;
        for(auto p:v)res+=p.second;
        return res;
    }
    ll res=0;
    vector<P> nv;
    for(auto p:v){
        int x=p.first>>bit&1,y=k>>bit&1;
        if(x<=y){
            nv.push_back(p);
            if(x<y)res+=p.second;
        }
    }
    return max(solve(nv,bit-1),res);
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d%d",&p[i].fi,&p[i].se);
    vector<P> v;
    for(int i=1;i<=n;i++)v.push_back(p[i]);
    printf("%lld\n",solve(v,30));
    return 0;
}