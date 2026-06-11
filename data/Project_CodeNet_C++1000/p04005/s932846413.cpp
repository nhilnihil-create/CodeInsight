#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int N = 1000000;
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
    vector<ll> d;
    if(a % 2 != 0){
        d.push_back(b * c);
    }else d.push_back(0);
    if(b % 2 != 0){
        d.push_back(a * c);
    }else d.push_back(0);
    if(c % 2 != 0){
        d.push_back(a * b);
    }else d.push_back(0);
    cout << *min_element(d.begin(), d.end()) << endl;
    
}