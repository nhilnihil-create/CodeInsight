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
    int n;
    cin >> n;
    int o=0,yon=0,ni=0;
    rep(i,n)
    {
        int a;
        cin >> a;
        if(a%2==1)o++;
        if(a%4!=0&&a%2==0)ni++;
        if(a%4==0)yon++;
    }
    if(yon>=o||(ni==0&&yon+1==o))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}