#include<bits/stdc++.h>
using namespace std;
#define INFTY 10000000000
typedef long long int ll;
const int MOD=1000000007;
using Graph = vector<vector<int>>;
using ipair = pair<ll,ll>;
bool operator< (const ipair a, const ipair b){return a.first < b.first;};
#define rep(i,n) for (ll i = 0; i < (n); ++i)
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){
    int n;cin>>n;
    vector<ll> a(n);
    rep(i,n)cin>>a[i];
    int cnt2=0,cnt4=0,ot;
    rep(i,n){
        if(a[i]%2==0&&a[i]%4!=0)cnt2++;
        else if(a[i]%4==0)cnt4++;
    }
    ot = n-cnt4-cnt2;
    if(ot<=cnt4+1&&cnt2==0&&cnt4>0||ot<=cnt4&&cnt2>0&&cnt4||n>1&&cnt2==n){
        cout<<"Yes";
    }else cout<<"No";
    return 0;
}