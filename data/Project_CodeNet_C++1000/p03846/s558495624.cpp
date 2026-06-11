#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const int N = 3e3+6;
const int mod = 1e9+7;
const ll inf = 1e18;
int a[N];
void solve(){
    int n;
    cin>>n;
    vector<int>v,w;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.pb(x);
    }
    sort(v.begin(),v.end());
    if(n%2==0){
        ll p2 = 1;
        for(int i=1;i<n;i+=2){
            w.pb(i);
            w.pb(i);
            p2*=2;
            p2%=mod;
        }
        bool match = true;
        for(int i=0;i<n;i++){
            if(v[i]!=w[i])match  = false;
        }
        if(match)cout<<p2<<endl;
        else cout<<0<<endl;

    }
    else{

        ll p2 = 1;
        w.pb(0);
        for(int i=2;i<n;i+=2){
            w.pb(i);
            w.pb(i);
            p2*=2;
            p2%=mod;
        }
        bool match = true;
        for(int i=0;i<n;i++){
            if(v[i]!=w[i])match  = false;
        }
        if(match)cout<<p2<<endl;
        else cout<<0<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--)solve();
    return 0;
}
