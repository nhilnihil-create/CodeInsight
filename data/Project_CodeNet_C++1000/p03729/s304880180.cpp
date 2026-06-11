#include <bits/stdc++.h>
#define rep(i,n) for (ll i=0; i<(n); i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    string A,B,C; cin >> A >> B >> C;
    if (A[A.size()-1]==B[0] && B[B.size()-1]==C[0]) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}