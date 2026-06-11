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
    int N, K;
    cin>>N>>K;
    int a, g, m;
    rep(i, N){
        cin>>a;
        if(i==0) {
            m=a;
            g=a;
            continue;
        }
        else{
            m=max(a, m);
            g=__gcd(a, g);
        }
    }
    if(K<=m&&K%g==0){
        cout<<"POSSIBLE"<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
}