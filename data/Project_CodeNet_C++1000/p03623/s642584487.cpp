#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1000000007;

int main(){
    int x,a,b;
    cin>>x>>a>>b;
    if(abs(x-a)>abs(x-b)) cout<<"B"<<endl;
    else cout<<"A"<<endl;
    return 0;
}