#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string a, b, c;
    cin >> a >> b >> c;
    queue<int> A, B, C;
    rep(i,a.size()){
        A.push(a[i] - 'a');
    }
    rep(j,b.size()){
        B.push(b[j] - 'a');
    }
    rep(k,c.size()){
        C.push(c[k] - 'a');
    }
    int turn = 0;
    while(true){
        if(turn == 0){
            if(A.empty()){
                cout << "A" << endl;
                return 0;
            }
            turn = A.front();
            A.pop();
        }
        else if(turn == 1){
            if(B.empty()){
                cout << "B" << endl;
                return 0;
            }
            turn = B.front();
            B.pop();
        }
        else if(turn == 2){
            if(C.empty()){
                cout << "C" << endl;
                return 0;
            }
            turn = C.front();
            C.pop();
        }
    }
    return 0;
}