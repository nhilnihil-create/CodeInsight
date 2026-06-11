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
    string S1,S2; cin >> S1 >> S2;
    ll ans = 1;
    rep(i,N){
        if(i == 0){
            if(S1[i] == S1[i+1]){
                ans *= 6;
                ans %= MOD;
                i++;
            }
            else{
                ans *= 3;
                ans %= MOD;
            }
        }
        else{
            if(S1[i] == S1[i+1]){
                if(S1[i-1] == S2[i-1]){
                    ans *= 2;
                    ans %= MOD;
                }
                else{
                    ans *= 3;
                    ans %= MOD;
                }
                i++;
            }
            else{
                if(S1[i-1] == S2[i-1]){
                    ans *= 2;
                    ans %= MOD;
                }
            }
        }
    }
    cout << ans << endl;

}
    

