#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main(){
    string o,e;
    cin >> o >> e;
    rep(i,e.size()){
        cout << o[i];
        cout << e[i];
    }
    if(o.size() > e.size()) cout << o[o.size()-1];
    cout << endl;
    return 0;
}