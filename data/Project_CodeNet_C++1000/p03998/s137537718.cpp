#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    string A,B,C;
    cin >> A >> B >> C;

    queue<char> a,b,c;

    rep(i,A.size()) {
        a.push(A[i]);
    }
    rep(i,B.size()) {
        b.push(B[i]);
    }
    rep(i,C.size()) {
        c.push(C[i]);
    }

    char now = a.front();
    a.pop();
    char ans;
    while(1) {
        if (now=='a') {
            if (a.size()==0) {
                ans = 'A';
                break;
            }
            else {
                now = a.front();
                a.pop();
            }
        }   
        if (now=='b') {
            if (b.size()==0) {
                ans = 'B';
                break;
            }
            else {
                now = b.front();
                b.pop();
            }
        }
        if (now=='c') {
            if (c.size()==0) {
                ans = 'C';
                break;
            }
            else {
                now = c.front();
                c.pop();
            }
        }
    }
    cout << ans << endl;
}
