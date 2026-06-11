#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <queue>

using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define ft first
#define sd second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef queue<int> QI;

const LL mod=1000000007;
LL powmod(LL a,LL b) {LL res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

LL ans;

int n;
int x[233333];

int main(){

    ans = 1;
    int bias = 0;
    int now =0;
    scanf("%d",&n);
    rep(i,0,n)scanf("%d",&x[i]);
    rep(i,0,n){
        if( x[i] >= (2*(i-bias)+1))now++;
        else{
            now ++;
            ans *=now;
            ans%=mod;
            now--;
            bias ++;
        }

    }
    LL jc = 1;
    rep(i,1,now+1)jc = (jc * i)%mod;
    ans = (ans%mod *jc);
    cout<<ans%mod<<endl;
    return 0;
}
