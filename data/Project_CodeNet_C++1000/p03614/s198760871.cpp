#include <iostream>
#include <algorithm>
#include <cstdio>
#include <regex>
#include <cmath>
#include <vector>
#include <queue>
#include <functional>
#include <numeric>
#include <iomanip>
#include <stack>
#include <string>
#include <map>
#include <set>
using namespace std;
typedef long long ll;

int main () {
    ll N;
    cin >> N;
    vector<ll> p(N);
    vector<ll> q(N);
    iota(q.begin(), q.end(), 1);
    for(auto &a:p) cin >> a;
    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        if(p[i] == q[i]) {
            ans++;
            if(i != N - 1) {
                ll tmp;
                tmp = p[i + 1];
                p[i + 1] = p[i];
                p[i] = tmp;
            }else {
                
            }
        }
    }
    cout << ans << endl;
}
