#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int in() {int x; cin>>x; return x;}
ll lin() {ll x; cin>>x; return x;}
string sin() {string x;cin>>x;return x;}
using graph = vector<vector<int>>;
using graph2 = vector<vector<pair<int, int>>>;

int main(){
    ll N=in();
    ll a[N];
    rep(i, N){
        cin>>a[i];
    }
    sort(a, a+N);
    ll b[N];
    rep(i, N){
        if(i==0) b[i]=a[i];
        else b[i]=a[i]+b[i-1];
    }
    int i;
    for (i=N-1;i>0;i--){
        if(b[i]>b[i-1]*3){
            break;
        }
    }
    std::cout<<N-i<<endl;
}