#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll N;
ll bit[2010000];

//aの位置にwを追加
void add(ll a,ll w){
    a++;
    for(int x=a;x<=N+1;x+=(x&(-x)) ){
        bit[x] += w;
    }
}

//v[0] + ... + v[a-1]
ll sum(ll a){
    ll ret=0;
    for(int x=a;x>0;x-=(x&(-x)) ){
        ret+=bit[x];
    }
    return ret;
}



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
    
    int n,m;
    cin>>n>>m;
    N = m+2;
    array<int,3> a[n];
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        a[i] = {r-l+1,l,r};
    }
    sort(a,a+n);
    int ans[m+1]={};
    int now = 0;
    for(int i=1;i<=m;i++){
        while(now<n && a[now][0] < i){
            add(a[now][1],1);
            add(a[now][2]+1,-1);
            now++;
        }
        for(int j=i;j<=m;j+=i){
            ans[i] += sum(j+1);
        }
        ans[i] += n-now;
        cout << ans[i] << "\n";
    }
}