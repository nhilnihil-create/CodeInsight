#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;

int main()
{
    string S, T;
    cin >> S >> T;
    int q;
    cin >> q;
    vector<int> a(q), b(q), c(q), d(q);
    for(int i=0; i<q; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--; c[i]--;
    }

    vector<int> x(S.size()+1), y(T.size()+1);
    x[0] = 0;
    y[0] = 0;
    for(int i=0; i<S.size(); i++){
        if(S[i] == 'A') x[i+1] = x[i] + 1;
        else x[i+1] = x[i] - 1;
    }
    for(int i=0; i<T.size(); i++){
        if(T[i] == 'A') y[i+1] = y[i] + 1;
        else y[i+1] = y[i] - 1;
    }

    for(int i=0; i<q; i++){
        int u = x[b[i]] - x[a[i]];
        int v = y[d[i]] - y[c[i]];
        if((u-v)%3==0) cout << "YES\n";
        else cout << "NO\n";
    }
}