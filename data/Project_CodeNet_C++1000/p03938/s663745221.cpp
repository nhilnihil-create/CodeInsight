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
    int N;
    cin >> N;
    vector<ll> p(N);
    for(ll& x: p){cin >> x; x--;}

    vector<ll> a(N), b(N);
    for(int i=0; i<N; i++) a[i] = i+1;
    for(int i=0; i<N; i++) b[p[i]] = N+i-a[p[i]];

    for(int i=1; i<N; i++){
        if(a[i-1] < a[i] && b[i-1] > b[i]) continue;
        ll m = max(a[i-1] - a[i] + 1, b[i] - b[i-1] + 1);
        a[i] += m; b[i] -= m;
    }

    // cout << "---\n";
    // for(ll& x: a) cout << x << " "; cout << endl;
    // for(ll& x: b) cout << x << " "; cout << endl;
    // cout << "---\n";

    if(b[N-1] <= 0){
        for(int i=0; i<N; i++) b[i] += 1-b[N-1];
    }

    for(ll& x: a) cout << x << " "; cout << endl;
    for(ll& x: b) cout << x << " "; cout << endl;
}