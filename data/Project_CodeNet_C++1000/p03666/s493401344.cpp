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
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;



int main(){
    int N; cin >> N;
    ll A,B,C,D; cin >> A >> B >> C >> D;
    bool ok = false;
    rep(i,N){
        if(B >= A-i*D+(N-1-i)*C && B <= A+(N-1-i)*D-i*C) ok = true;
    }
    cout << (ok?"YES":"NO") << endl;
}