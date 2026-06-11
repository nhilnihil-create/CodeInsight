#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1000000007;

int main(){
    int a,b;
    cin>>a>>b;
    map<int,int> strength;
    rep(i,13) strength[i+1]=i;
    strength[1]=13;
    if(strength[a]>strength[b]) cout<<"Alice"<<endl;
    else if(strength[a]<strength[b]) cout<<"Bob"<<endl;
    else cout<<"Draw"<<endl;
    return 0;
}