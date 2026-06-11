#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#define fi first
#define se second
#define pb(i) push_back(i)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define mes(a,b) memset(a,b,sizeof(a))
#define sbs(i,j) substr(i,j)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6+10;
const int INF = 0x3f3f3f3f;
const int inf = - INF;
const int mod = 1e9+7;
const double pi = acos(-1.0);


int main(){
    std::ios::sync_with_stdio(false);
    ll x;
    cin>>x;
    if(x<=6) cout<<1<<endl;
    else{
        if(x%11==0) cout<<x/11*2<<endl;
        else{
            ll before = x/11*2;
            x-=before/2*11;
            if(x<=6) before++;
            else before+=2;
            cout<<before<<endl;
        }
    }
    return 0;
}