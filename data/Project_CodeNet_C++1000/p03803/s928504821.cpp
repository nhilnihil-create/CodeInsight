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
    int a,b;cin>>a>>b;
    int A,B;
    vector<int>power={2,3,4,5,6,7,8,9,10,11,12,13,1};
    rep(i,power.size()){
        if(a==power.at(i)){
            A=i;
        }
        if(b==power.at(i)){
            B=i;
        }
    }
    if(A>B)cout<<"Alice"<<endl;
    else if(A==B) cout<<"Draw"<<endl;
    else cout<<"Bob"<<endl;
}
