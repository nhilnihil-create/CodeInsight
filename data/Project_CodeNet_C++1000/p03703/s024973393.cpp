#include <bits/stdc++.h>
using namespace std;
int n,k,a[200005],b[200005],bit[530000];
long long pre[200005],ans;
vector<long long> v;
map<long long,int> m;
void upd(int x,int val) {
    while (x!=0) {
        bit[x]+=val; x-=(x&(-x));
    }
}
int que(int x) {
    int ret=0;
    while (x!=2*524288) {
        ret+=bit[x]; x+=(x&(-x));
    }
    return ret;
}
int main() {
    cin>>n>>k;
    for (int i=1; i<=n; i++) {cin>>a[i]; b[i]=a[i]-k;}
    v.push_back(0);
    for (int i=1; i<=n; i++) {pre[i]=pre[i-1]+b[i]; v.push_back(pre[i]);}
    sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());
    for (int i=0; i<v.size(); i++) m[v[i]]=i+1;
    for (int i=1; i<=n; i++) upd(m[pre[i]],1);
    for (int i=1; i<=n; i++) {
        ans+=que(m[pre[i-1]]);
        upd(m[pre[i]],-1);
    }
    cout<<ans<<'\n';
}