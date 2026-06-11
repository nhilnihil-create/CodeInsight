#include <bits/stdc++.h>
using namespace std;
 
typedef long long           ll;
typedef vector<int>         vi;
typedef vector<ll>          vll;

#define ff                  first
#define sf                  scanf
#define pf                  printf
#define ss                  second
#define ppb                 pop_back
#define pb                  push_back
#define MP                  make_pair
#define MAXN                10000
#define MOD                 100000007
#define inf                 0x3f3f3f3f
#define PI                  (2.0*acos(0.0))
#define INF                 0x3f3f3f3f3f3f3f3f
#define rev(v)              reverse(all(v))
#define all(v)              v.begin(), v.end()
#define __lcm(x, y)         (x * y) / __gcd(x, y)
#define FOR(i, x, y)        for(int i = x; i < y; i++)
#define RFOR(i, x, y)       for(int i = x; i >= y; i--)
#define MEM(arr, val)       memset(arr, val, sizeof(arr));
#define unq(v)              (v).resize(unique(all(v)) - v.begin())
#define READ()              freopen("input.txt", "r", stdin)
#define WRITE()             freopen("output.txt", "w", stdout)
#define si(n)               scanf("%d", &n)
#define sl(n)               scanf("%lld", &n)
#define sii(a, b)           scanf("%d %d", &a, &b)
#define sll(a, b)           scanf("%lld %lld", &a, &b)
#define siii(a, b, c)       scanf("%d %d %d", &a, &b, &c)
#define slll(a, b, c)       scanf("%lld %lld %lld", &a, &b, &c)
#define siiii(a, b, c, d)   scanf("%d %d %d %d", &a, &b, &c, &d)
#define sllll(a, b, c, d)   scanf("%lld %lld %lld %lld", &a, &b, &c, &d)
#define vout(v)             for(int i = 0; i < v.size(); i++) {cout << v[i]; if(i < v.size() - 1) cout << ' '; else cout << endl;}

int main(){
        string A, B, C; cin >> A >> B >> C;
        int a = 1, b = 0, c = 0;
        while(1){
        	if(a == 1){
        		if(!A.size()) break;
        		if(A[0] == 'a'){
        			a = 1, b = 0, c = 0;
        		} else if(A[0] == 'b'){
        			a = 0, b = 1, c = 0;
        		} else {
        			a = 0, b = 0, c = 1;
        		}
        		A.erase(A.begin());
        	} else if(b == 1){
        		if(!B.size()) break;
        		if(B[0] == 'a'){
        			a = 1, b = 0, c = 0;
        		} else if(B[0] == 'b'){
        			a = 0, b = 1, c = 0;
        		} else {
        			a = 0, b = 0, c = 1;
        		}
        		B.erase(B.begin());
        	} else {
        		if(!C.size()) break;
        		if(C[0] == 'a'){
        			a = 1, b = 0, c = 0;
        		} else if(C[0] == 'b'){
        			a = 0, b = 1, c = 0;
        		} else {
        			a = 0, b = 0, c = 1;
        		}
        		C.erase(C.begin());
        	}
        }
        if(a == 1) puts("A");
        else if(b == 1) puts("B");
        else puts("C");


    return 0;
}