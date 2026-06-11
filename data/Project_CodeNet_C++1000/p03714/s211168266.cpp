#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1000000007;
const int INF = 1e9;

const int mod = 1000000007;
const int inf = 1e9;
#define PI acos(-1);
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};


int main(){
    int n;
    cin >> n;
    vector<ll> a(3*n);
    for(int i = 0; i < 3*n; i++) {
        cin >> a[i];
    }
    priority_queue<ll> q2;
    priority_queue<ll, vector<ll>, greater<ll>> q1;
    ll sumA = 0, sumB = 0;
    for(int i = 0; i < n; i++) q1.push(a[i]), sumA += a[i];
    for(int i = 2*n; i < 3*n; i++) q2.push(a[i]), sumB += a[i];
    vector<ll> A(3*n,0), B(3*n,0);
    A[n-1] = sumA;
    B[2*n] = sumB;
    for(int i = n; i < 2*n; i++) {
        int now = q1.top();
        if(now < a[i]){
            sumA = sumA + a[i] - now;
            q1.pop();
            q1.push(a[i]);
            A[i] = sumA;
        }else{
            A[i] = sumA;
        }
    }
    for(int i = 2*n-1; i >= n; i--) {
        int now = q2.top();
        if(now > a[i]) {
            sumB = sumB - now + a[i];
            q2.pop();
            q2.push(a[i]);
            B[i] = sumB;
        }else{
            B[i] = sumB;
        }
    }
    ll ans = -1e18;
    for(int i = n-1; i < 2*n; i++) {
        ll now = A[i] - B[i+1];
        chmax(ans, now);
    }
    cout << ans << endl;
}