#include <bits/stdc++.h>
template<class T> inline bool chmin(T&a, T b){if(a > b){a = b; return true;}else{return false;}}
template<class T> inline bool chmax(T&a, T b){if(a < b){a = b; return true;}else{return false;}}
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1.0)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    string a, b, ans;
    cin >> a >> b;
    if(a.size() != b.size())ans = (a.size() > b.size() ? "A" : "B");
    else{
        ans = "C";
        rep(i, a.size()){
            int A = a[i] - '0';
            int B = b[i] - '0';
            if(A == B)continue;
            ans = ans = (A > B ? "A" : "B");
            break;
        }
    }
    if(ans == "A")cout << "GREATER" << endl;
    if(ans == "B")cout << "LESS" << endl;
    if(ans == "C")cout << "EQUAL" << endl;
}