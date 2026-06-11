#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()
int main(){
    int x,a,b;cin>>x>>a>>b;
    if(a-b>=0)cout<<"delicious"<<endl;
    else if(b-a<=x) cout<<"safe"<<endl;
    else cout<<"dangerous"<<endl;
}
