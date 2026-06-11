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
    rep(i,n){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int ans =0;
    int i = 0;
    while(i<n-1){
        if(a[i]!=a[i+1]&&i==n-2){ans+=2;i++;}
        else if(a[i]!=a[i+1]){ans++;i++;}
        else{
            int l=1;
            while(i<n-1&&a[i]==a[i+1]){
                l++;
                i++;
            }
           // cout<<l<<endl;
            i++;
            if(l%2!=0)ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}