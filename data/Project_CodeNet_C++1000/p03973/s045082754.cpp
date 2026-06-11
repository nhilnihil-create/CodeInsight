// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cppみたいなかんじで
#include <bits/stdc++.h>
#define mod 1000000007
#define INF LLONG_MAX
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
using namespace std;
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};
vector<ll> w(100);

// index が条件を満たすかどうか
bool isOK(ll index, ll key) {
    if (w[index] >= key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
ll binary_search(ll key) {
    ll ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    ll ok = (ll)w.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;

        if (isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}
 
int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
 
    ll a,b,d,m,n,maxi=0,f=0,mini=INF,sum=0;
    string str;
    cin>>n;
    vector<ll> v(n);
    rep(i,n) cin>>v[i];
    sum+=v[0]-1;
    v[0]=1;
    ll size=2;
    mini=1;
    ll lastsum=0;
    for(ll i=1;i<n;i++){
        lastsum=sum;
        if(v[i]<size) a=1;
        else if(v[i]==size) {
            size++;
        }else{
            ll effective =v[i]-1;
            sum+=effective/size;
        }
        //cout<<v[i]<<" "<<sum-lastsum<<" "<<endl;
    }
    
    cout<<sum<<endl; 
    return 0;
}//14159265358979