#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
//const int N = 1000000;
const ll mod = 1000000007;
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
 
ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}
 
/*------------------------------------------------------------------*/
 
int main(){
    ll a, b, c; cin >> a >> b >> c;
    ll count = 0;
    if(a % 2 == 1 || b % 2 == 1 || c % 2 == 1){
        cout << count << endl;
        return 0;
    }
    while(true){
        ll t = a;
        ll s = b;
        ll u = c;
        a += s / 2 + u / 2 - t;
        b += u / 2 + t / 2 - s;
        c += t / 2 + s / 2 - u;

        count++;
        //cout << a << " " << b << " " << c << endl;
        if(a % 2 == 1 || b % 2 == 1 || c % 2 == 1){
            cout << count << endl;
            return 0;
        }
        if(a == b && c == a){
            cout << -1 << endl;
            return 0;
        }
    }
}
