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
    int K, T;
    cin>>K>>T;
    int a, m=0;
    rep(i, T){
        cin>>a;
        m=max(a, m);
    }
    cout<<max(0, m-(K-m+1))<<endl;
}