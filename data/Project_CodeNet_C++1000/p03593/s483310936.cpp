#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
const ll MAX = 1001001;
const ll MOD = 1000000007;
int main()
{
    ll h, w;
    cin >> h>>w;
    vector<vector<char>>a(h, vector<char>(w));
    vector<ll>c(26);
    rep(i, h) {
        rep(j, w) {
            cin>>a[i][j];
            c[a[i][j]-'a']++;
        }
    }
    if (h==1||w==1) {
        ll co=0;
        rep(i, 26) {
            if (c[i]%2==1) {
                co++;
            }
        }
        if (co==1&&h*w%2==1) {
            cout<<"Yes"<<endl;
        }
        else if (co==0&&h*w%2==0) {
            cout<<"Yes"<<endl;
        }
        else {
            cout<<"No"<<endl;
        }
    }
    else {
        ll co=0;
        ll co4=0;
        rep(i, 26) {
            if (c[i]%2==1) {
                co++;
            }
            if (c[i]>=4) {
                co4+=c[i]/4;
            }
        }
        if (co==1&&h*w%2==1&&co4==h/2*(w/2)) {
            cout<<"Yes"<<endl;
        }
        else if (co==0&&h*w%2==0&&co4==h/2*(w/2)) {
            cout<<"Yes"<<endl;
        }
        else {
            cout<<"No"<<endl;
        }
    }
}