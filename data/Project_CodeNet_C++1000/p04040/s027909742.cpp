#include<algorithm>
#include<complex>
#include<ctype.h>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<map>
#include<math.h>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<stdio.h>
#include<string>
#include<string>
#include<vector>

using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define br() p("")
#define pn(s) cout << (#s) << " " << (s) << endl
#define p_yes() p("Yes")
#define p_no() p("No")

const ll mod = 1e9 + 7;
const ll inf = 1e18;

template < typename T >
void vprint(T &V){
	for(auto v : V){
    	cout << v << " ";
	}
	cout << endl;
}

const int N_MAX = 200010;
ll Per[N_MAX] = {}; // n!
ll Per_inv[N_MAX] = {}; //(n!)^-1

ll nCr(ll n, ll r){
    if(n<r) return 0;
 
    if (n == r || r == 0)
        return 1;
    else
        return Per[n] * Per_inv[n-r] % mod * Per_inv[r] % mod;  
}
 
// a^b mod p
ll mod_pow(ll a, ll b){
    if(b==0) return 1;
 
    // 肩が奇数
    if(b%2==1){
        return a * mod_pow(a, b-1) % mod;
    }
    else{
        return mod_pow(a*a % mod, b/2) % mod;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll H, W, A, B;
    cin >> H >> W >> A >> B;

    // nCr高速化準備
    Per[1] = 1;
    FOR(i, 2, N_MAX){
        Per[i] = i * Per[i-1] % mod;
    }
    Per_inv[1] = 1;
    FOR(i, 2, N_MAX){
        Per_inv[i] = mod_pow(Per[i], 1000000005);
    }

    ll sum = 0;
    FOR(b, B, W){
        sum += nCr(H-A-1+b, b) * nCr(A-1+W-1-b, A-1);
        sum %= mod;
    }

    p(sum);
    
    return 0;
}