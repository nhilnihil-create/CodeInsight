#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <string>
#define _repargs(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _repargs(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define inf 2000000007
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
template <typename T>
inline void output(T a, int p = 0) {
    if(p) cout << fixed << setprecision(p)  << a << "\n";
    else cout << a << "\n";
}
// end of template

void fi(int a) {
//    cout << a << endl;
    if(a % 2 == 0) output("First");
    else output("Second");
    exit(0);
}

void se(int a) {
//    cout << a <<  endl;
    if(a % 2 == 0) output("Second");
    else output("First");
    exit(0);
}

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

template <typename T> inline void voutput(T &v){
    rep(i, v.size()){
        if (i) cout << " " << v[i];
        else cout << v[i];
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // source code
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    
    
    int loop = 0;
    while(1){
        int even = 0;
        int odd = 0;
        rep(i, N){
            if(A[i] % 2 == 0) even++;
            else odd++;
        }
        
        if(odd == 1 && even % 2 == 0){
            
            rep(i, N) {
                if(A[i] == 1){
                    se(loop);
                }
                if(A[i] % 2 == 1) A[i]--;
            }
            ll g = A[0];
            rep(i, N) g = gcd(g, A[i]);
            rep(i, N) A[i] /= g;
        }
        else{
            if(even % 2 == 0){
                se(loop);
            }
            else{
                fi(loop);
            }
        }
        loop++;
    }
    
    
    return 0;
}