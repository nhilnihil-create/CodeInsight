#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string a, b;
    cin >> a >> b;
    int sa = a.size(), sb = b.size();
    if(sa < sb) cout << "LESS" << endl;
    else if(sa > sb) cout << "GREATER" << endl;
    else{
        rep(i,sa){
            if(a[i] == b[i]) continue;
            if(a[i] < b[i]){
                cout << "LESS" << endl;
                return 0;
            }
            if(a[i] > b[i]){
                cout << "GREATER" << endl;
                return 0;
            }
        }
        cout << "EQUAL" << endl;
    }
    return 0;
}
