#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<double> VL;
typedef vector<string> VS;
typedef vector<PLL> VP;
typedef vector<ll> VLL;
#define rep(i,n) for (ll i=0; i<(ll)(n); i++)
#define repd(i,n) for (ll i=n-1; i>=0; i--)
#define rept(i,m,n) for(ll i=m; i<n; i++)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define PF push_front
#define PB push_back
#define SORT(V) sort((V).begin(), (V).end())
#define RVERSE(V) reverse((V).begin(), (V).end())
#define paired make_pair
#define PRINT(V) for(auto v : (V)) cout << v << " "
int ctoi(char c) { if (c >= '0' && c <= '9') { return c - '0'; } return 0; } //charを整数に

int main()
{
    ll N,A,B;
    cin >> N >> A >> B;
    if(A>B){
        cout << 0 << endl;
    }
    else if(N==1){
        if(A==B){
            cout << 1 << endl;
        }    
        else{
            cout << 0 << endl;
        }
    }
    else{
        if(A>B){
            cout << 0 << endl;
        }
        if(A==B){
            cout << 1 << endl; 
        }
        else{
            cout << (B-A)*(N-2)+1 << endl;
        }
    }
}