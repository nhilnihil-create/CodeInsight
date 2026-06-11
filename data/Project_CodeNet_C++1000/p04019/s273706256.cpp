#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    string T;
    cin >> T;
    bool N = false;
    bool S = false;
    bool E = false;
    bool W = false;
    rep(i,T.size()){
        if (T[i] == 'S') S = true;
        if (T[i] == 'E') E = true;
        if (T[i] == 'W') W = true;
        if (T[i] == 'N') N = true;
    }
    if (S && !N) cout << "No" << endl;
    else if (N && !S) cout << "No" << endl;
    else if (E && !W) cout << "No" << endl;
    else if (W && !E) cout << "No" << endl;
    else cout << "Yes" << endl;
}