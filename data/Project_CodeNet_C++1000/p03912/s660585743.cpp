#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<tuple>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define Per(i,sta,n) for(int i=n-1;i>=sta;i--)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;

int n,m,x[100010],d[100010]={0};
int a[100010]={0},b[100010]={0};

void solve(){
    cin >> n >> m;
    rep(i,n){
        cin >> x[i];
        d[x[i]]+=1;
    }
    rep(i,100001){
        a[i%m]+=d[i];
        b[i%m]+=2*(d[i]/2);
    }
    ll ans=0;
    rep(i,m){
        //cout << a[i]<< " " << b[i] << endl;
    }
    for (int k=0;m-k>=k;k++){
        if ((m-k)%m==k) {
            ans+=a[k]/2;
            //cout << k << " " << a[k]/2 << endl;
        }
        else{
            int s=min(a[k],a[m-k]);
            int l1=max(0,s-(a[k]-b[k])),l2=max(0,s-(a[m-k]-b[m-k]));
            ans+=s+(b[k]-l1)/2+(b[m-k]-l2)/2;
            //cout << k << " " <<  m-k << " " << s+(b[k]-l1)/2+(b[m-k]-l2)/2 << " " << endl;

        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(50);
    solve();
}