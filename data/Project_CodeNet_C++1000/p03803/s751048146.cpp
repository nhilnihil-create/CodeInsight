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
    int A,B; cin >> A >> B;
    if (A==B){
        cout << "Draw" << endl;
        return 0;
    }
    else if (A==1 && B!=1){
        cout << "Alice" << endl;
        return 0;
    }
    else if (B==1 && A!=1){
        cout << "Bob" << endl;
        return 0;
    }
    
    if(A>B) cout << "Alice" << endl;
    else cout << "Bob" << endl;
    return 0;
}