#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1000000007;
const LL LINF=1LL<<60;
const int INF=1<<30;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};



vector<LL> fact;
vector<LL> inver(200001);
 
LL combi(int n,int r){
    if(n<r||n<0||r<0) return 0;
    return fact[n]%mod*inver[n-r]%mod*inver[r]%mod;
}
 
 
LL fpow(LL a, LL n){
    LL x = 1;
    while(n > 0){
        if(n&1){
            x=x*a%mod;
        }
        a=a*a%mod;
        n >>= 1;
    }
    return x;
}
 
void set_combi(){
    LL s=1;
    fact.push_back(1);
    for(int i=1;i<=200000;i++){
        s*=i;
        s%=mod;
        fact.push_back(s);
    }
    inver[200000]=fpow(fact[200000],mod-2);
    for(int i=199999;i>=0;i--){
        inver[i]=inver[i+1]*(i+1)%mod;
    }
}
 

int main(){
    set_combi();
    int n;cin >> n;
    LL ans = 1;
    LL c = 0;
    for (int i = 0; i < n; i++) {
        LL x;cin >> x;
        if(x < 2 * c + 1){
            ans = ans * (c + 1) % mod;
            c--;
        }
        c++;
    }
    ans = ans * fact[c] % mod;
    cout << ans << endl;
    return 0;
}
