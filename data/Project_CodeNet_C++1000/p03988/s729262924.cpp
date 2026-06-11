#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
    int n;
    cin>>n;
    V<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(all(a));
    ll d=*max_element(all(a));
    map<int,int> mp;
    if(d%2==0){
        mp[d/2];
        for(int i=0;i<n;i++){
            if(a[i]<d/2){
                    cout<<"Impossible"<<"\n";
                    return 0;
                }
            else if(i&&a[i]-a[i-1]>1){
                 cout<<"Impossible"<<"\n";
                    return 0;
            }
            mp[a[i]]++;
        }
        for(auto p:mp){
            if(p.fi==d/2){
                if(p.se!=1){
                    cout<<"Impossible"<<"\n";
                    return 0;
                }
            }
            else if(p.se<2){
                cout<<"Impossible"<<"\n";
                    return 0;
            }
        }
    }else{
        mp[(d+1)/2];
        for(int i=0;i<n;i++){
            if(a[i]<(d+1)/2){
                    cout<<"Impossible"<<"\n";
                    return 0;
            }
            else if(i&&a[i]-a[i-1]>1){
                 cout<<"Impossible"<<"\n";
                    return 0;
            }
            mp[a[i]]++;
        }
        for(auto p:mp){
            if(p.fi==(d+1)/2){
                if(p.se!=2){
                      cout<<"Impossible"<<"\n";
                    return 0;
                }
            }
            if(p.se<2){
                cout<<"Impossible"<<"\n";
                    return 0;
            }
        }
    }
    cout<<"Possible"<<"\n";
}
