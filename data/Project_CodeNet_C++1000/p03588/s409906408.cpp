#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    vector<pair<ll, ll>> standing;
    Rep (i, N) {
        cin >> A[i] >> B[i];
        standing.push_back(make_pair(A[i], B[i]));
    }

    sort(standing.begin(), standing.end());
    reverse(standing.begin(), standing.end());

    cout << standing[0].first + standing[0].second << endl;
}