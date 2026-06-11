#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1000000007;

int main(){
    int a,b;
    cin>>a>>b;
    cout<<(a+b)%24<<endl;
    return 0;
}