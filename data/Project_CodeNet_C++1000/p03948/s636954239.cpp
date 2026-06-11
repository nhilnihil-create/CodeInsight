#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstring>

using namespace std;
// ascending order
#define vsort(v) sort(v.begin(), v.end())
// descending order
#define vsort_r(v) sort(v.begin(), v.end(), greater<int>())
#define vunique(v) unique(v.begin(), v.end())
#define mp make_pair
#define ts(x) to_string(x)
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define repm(i, a, b) for(int i = (int)a; i > (int)b; i--)
#define bit(a) bitset<8>(a)
#define des_priority_queue priority_queue<int, vector<int>, greater<int> >
#define all(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1e18;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

    ll N, T;
    cin >> N >> T;
    int max_a[N], A[N];
    int max_v = 0;
    rep(i, 0, N) cin >> A[i];

    for(int i = N - 1; i >= 0; i--) {
        max_v = max(max_v, A[i]);
        max_a[i] = max_v;
    }

    max_v = -1e9 - 7;
    int rsl = 0;
    rep(i, 0, N) {
        int tmp = max_a[i] - A[i];
        if(max_v < tmp) {
            max_v = tmp;
            rsl = 1;
        } else if(max_v == tmp) rsl++;
    }
    cout << rsl << endl;



}
