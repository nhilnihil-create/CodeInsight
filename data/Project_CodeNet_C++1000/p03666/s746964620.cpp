#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 100005
#define INF 1000000005
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
#define SZ(x) int(x.size())
#define IN(a) cin>>(a)
#define OUT(a) cout<<(a)<<endl
typedef pair<int,int> P;
const int MAX = 1000005;
const int MOD = 998244353;
int main(){
    ll n;
    cin>>n;
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    bool f=false;
    REP(i,n){
        if(-d*i+c*(n-1-i)<=(b-a)&&(b-a)<=d*(n-1-i)-c*i){
            f=true;
            break;
        }
    }
    if(f)OUT("YES");
    else OUT("NO");
    return 0;
}