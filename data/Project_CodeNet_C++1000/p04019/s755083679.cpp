#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    string a;
    cin >> a;
    
    bool n = false, w=false, s=false, e=false;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 'N') n = true;
        else if (a[i] == 'W') w = true;
        else if (a[i] == 'S') s = true;
        else e = true;
    }

    bool ans = true;
    if (n && s);
    else if (!n && !s);
    else ans = false;

    if (w && e) ;
    else if (!w && !e);
    else ans = false;

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}