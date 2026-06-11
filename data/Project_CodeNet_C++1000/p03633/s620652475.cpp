#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define MAX_N 1010
#define MAX_M 100010
const long long mod = pow(10, 9) + 7;
#define vec vector<int>
#define vecll vector<ll>
#define vecllvec vector<vector<ll>>
#define vecb vector<bool>
#define vecBvec vector<vector<bool>>
#define vecst vector<string>
#define veche vector<char>
#define vecd vector<double>
#define vecvec vector<vector<int>>
#define vecDvec vector<vector<double>>
#define vecHvec vector<vector<char>>
#define all(x) (x).begin(),(x).end()
#define ent cout<<endl
#define printvec(vec) for(int aqw=0;aqw<vec.size();aqw++){cout<<vec[aqw]<<" ";}ent;
#define rep1(n) for(ll i = 0; i < (n); ++i)
#define rep2(i, n) for(ll i = 0; i < (n); ++i)
#define rep3(i, a, b) for(ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for(ll i = (a); i < (b); i += (c))
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//#define INF 1e+9
#define print(x) cout<<x<<endl;
using P = pair<int, int>;
#define PLL pair<ll, ll>;
#define MAX_V 10010
#define PI 3.141592653589793
#define vecP vector<P>
//cout << setprecision(15) << std::fixed;


ll gcd(ll a,ll b){
    if(a%b>0){
        gcd(b,a%b);
    }
    else{
        return b;
    }
}

ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}

int main(){
    int n;
    ll x,y;
    cin>>n>>x;
    for(int i;i<n-1;i++){
        cin>>y;
        x=lcm(x,y);
    }
    print(x);

    
    return 0;
}

