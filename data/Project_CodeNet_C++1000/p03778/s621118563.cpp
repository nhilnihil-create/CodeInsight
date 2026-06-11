#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1000000007;

int main(){
    int w,a,b;
    cin>>w>>a>>b;
    if(a>b) swap(a,b);
    if(a<=b && b<=a+w) cout<<"0"<<endl;
    else cout<<min(b-a,b-a-w)<<endl;
    return 0;
}