#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int main(){
    cout << fixed << setprecision(10);
    int n,a,b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int all = 0, kai = 0;
    rep(i,n){
        if(s[i] == 'a' && all < a+b){
            cout << "Yes" << endl;
            all++;
        }else if(s[i] == 'b' && all < a+b && kai < b){
            cout << "Yes" << endl;
            all++;
            kai++;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}