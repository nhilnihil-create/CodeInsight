#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=((n)-1);(i)>=0;(i)--)
#define itn int
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
const long long INF = 1LL << 60;
const int MOD = 1000000007;
vector <int> a;
signed main(void){
    int n; cin>>n;
    a.resize(n);
    rep(i,n) cin>>a[i];
    sort(a.begin(),a.end());
    bool same = true;
    
    rep(i,n-1) if(a[i] != a[i+1]) same = false;
    if(abs(a[0] - a[n-1])>=2) {cout<<"No"<<endl; return 0;}
    if(same){
        if(a[0] == n-1 || 2*a[0] <=n) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }else{
        int p = count(all(a), a[0]);
        int q = n-p;
        if(p<a[n-1]&& 2*(a[n-1]-p)<=q) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
