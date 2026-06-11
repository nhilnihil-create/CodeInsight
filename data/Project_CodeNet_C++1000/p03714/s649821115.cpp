#include <bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define vi vector<int>
#define pb push_back
#define pi pair<int,int>
#define vp vector<pair<int,int> >
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define inf 1000000000000000000

using namespace std;

void run();

void init() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cout<<fixed;
}

signed main(){
    init();
    run();
    return 0;
}

void run(){
    int n;
    cin>>n;
    vi a(3*n);
    rep(i,3*n){
        cin>>a[i];
    }
    vi s1;
    priority_queue<int> q1;
    int s=0;
    rep(i,n){
        s+=a[i];
        q1.push(-a[i]);
    }
    s1.pb(s);
    Rep(i,n,2*n){
        q1.push(-a[i]);
        int t=q1.top();
        if(t!=-a[i]){
            s=s+t+a[i];
        }
        q1.pop();
        s1.pb(s);
    }
    vi s2;
    priority_queue<int> q2;
    s=0;
    for(int i=3*n-1;i>=2*n;i--){
        s+=a[i];
        q2.push(a[i]);
    }
    s2.pb(s);
    for(int i=2*n-1;i>=n;i--){
        q2.push(a[i]);
        int t=q2.top();
        if(t!=a[i]){
            s=s-t+a[i];
        }
        q2.pop();
        s2.pb(s);
    }
    reverse(all(s2));
    int ans=-inf;
    rep(i,s1.size()){
        ans=max(ans,s1[i]-s2[i]);
    }
    cout<<ans<<endl;
}