#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(long long i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



const int MAX_C = 100;
long long Com[MAX_C][MAX_C];
void COMinit() {
    Com[0][0] = 1;
    for (int i = 1; i < MAX_C; ++i) Com[0][i] = 0;
    for (int i = 1; i < MAX_C; ++i) {
        Com[i][0] = 1;
        for (int j = 1; j < MAX_C; ++j) {
            Com[i][j] = (Com[i-1][j-1] + Com[i-1][j]);
        }
    }
}
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return Com[n][k];
}



int main(){
    ll n,a,b; cin>>n>>a>>b;
    vector<ll> w(n), v(n);
    rep(i,n) cin>>w[i];
    
    sort(w.begin(), w.end(), greater<ll>());
    v[0] = w[0]; // w: もと、 v: 累積和
    rep(i,n-1) v[i+1]+=v[i]+w[i+1];
    double res=(double)v[a-1]/a;
    cout<<fixed<<setprecision(20)<<res<<endl;

    ll cnt=1, left=0; //cnt: w[a-1] ... w[a+cnt-2]まで同じ数, left: w[a-2]から左へleft個同じ数
    for(ll i = a; i < n; i++){
        if(w[i]==w[i-1]) cnt++;
        else break;
    }
    for(ll i=a-2; i>=0; i--){
        if(w[i]==w[i+1]) left++;
        else break;
    }
    ll com=0;
    COMinit();
    if(w[a-1]!=w[0]){
        com = COM(cnt+left, left+1);
    }else{
        for(ll i = left+1; i<=min(left+b-a+1ll, cnt+left); i++){
            com+=COM(cnt+left, i);
        }
    }
    cout<<com<<endl;
    return 0;
}