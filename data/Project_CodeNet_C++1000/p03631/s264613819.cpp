#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1000000007;

int main(){
    string n;
    cin>>n;
    if(n[0]==n[2]) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}