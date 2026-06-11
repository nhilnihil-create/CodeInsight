#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
//#define MOD 1000000007
#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;


int main(){
    int N,M; cin >> N >> M;
    vector<int> X(N);
    rep(i,N) cin >> X[i];
    sort(X.begin(),X.end());
    vector<int> v1(M),v2(M);
    rep(i,N-1){
        if(X[i] == X[i+1]){
            v1[X[i]%M]+=2;
            i++;
        }
    }
    rep(i,N){
        v2[X[i]%M]++;
    }
    int ans = 0;
    ans += v2[0]/2;
    if(M%2 == 0) ans += v2[M/2]/2;
    repr(i,1,M/2+1){
        if(M%2 == 0 && i == M/2) continue;
        int k = min(v2[i],v2[M-i]);
        ans += k;
        int d1 = v2[i]-v1[i];
        int d2 = v2[M-i]-v1[M-i];
        if(k > d1) v1[i] = v1[i]-(k-d1);
        if(k > d2) v1[M-i] = v1[M-i]-(k-d2);
    }
    repr(i,1,M){
        if(M%2 == 0 && i == M/2) continue;
        if(v1[i] > 0) ans += v1[i]/2;
    }
    cout << ans << endl;

}

    

