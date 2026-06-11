#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1e9+7;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(b-a==c-b) cout<<"YES"<<endl;
    else  cout<<"NO"<<endl;
    cout<<endl;
    return 0;
}
