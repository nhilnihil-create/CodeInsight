#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define ALL(v) ((v).begin(),(v).end())
#define COUT(x) cout<<(x)<<"\n"

map<int,int>map1;

void prime(int n){
    int r = sqrt(n);
    for(int i=2;i<r+1;i++){
        while(n%i==0){
            n /= i;
            map1[i]++;
        }
    }
    if(n>1)map1[n]++;
}


int main(){
    int n;
    cin >> n;
    ll ans = 1;
    for(int i=1;i<n+1;i++)prime(i);
    for(const auto& x:map1){
        int num = x.second;
        ans *= num+1;ans%=MOD;
    }
    COUT(ans);
    return 0;
}