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
    int X,A,B; cin >> X >> A >> B;
    //賞味期限Ａ日前
    //買ってからB日後
    //賞味期限Ｘ日
    if (A>B) cout << "delicious" << endl;
    else if (A==B) cout << "delicious" << endl;
    else if (A<B && X>=B-A) cout << "safe" << endl;
    else if (A<B && X<B-A) cout << "dangerous" << endl;
    return 0;
}