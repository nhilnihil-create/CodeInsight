#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long int ll;
typedef unsigned long long ull;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;

int main()
{
    int x,y;
    cin>>x>>y;
    if((ll)x*y>=0){
        if(x<=y)cout<<y-x<<endl;
        else if(x==0||y==0) cout<<abs(x)+abs(y)+1<<endl;
        else if(x>0) cout<<x-y+2<<endl;
        else cout<<x-y+2<<endl;
    }else cout<<abs(abs(y)-abs(x))+1<<endl;
    return 0;
}
