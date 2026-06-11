#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n); ++i)
typedef long long ll;

const int mod = 1e9+7;
const int INF = 2000000;
const double PI = acos(-1.0);

int main() {
    
    string S;
    cin >> S;

    bool c[4] = {false};

    for(int i = 0; i < S.size(); i++) {
        if(S[i] == 'N') c[0] = true;
        else if(S[i] == 'S') c[1] = true;
        else if(S[i] == 'W') c[2] = true;
        else c[3] = true; 
    }
    if((c[0] && c[1] && !c[2] && !c[3]) ||
        (!c[0] && !c[1] && c[2] && c[3]) ||
        (c[0] && c[1] && c[2] && c[3])) {
            cout << "Yes" << endl;
        }
    else cout << "No" << endl;
    
}