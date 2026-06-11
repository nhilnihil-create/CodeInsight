#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    string s; cin >> s;
    int N = s.size();
    int pcnt = 0;
    rep(i, N){
        if(s[i] == 'p')pcnt++;
    }

    int at = N/2;
    cout << at-pcnt << endl;

    return 0;
}