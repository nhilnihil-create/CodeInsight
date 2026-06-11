#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll Div(ll a, ll b){
    if(a >= 0) return a / b;
    return -((- a - 1)/ b) - 1;
}

int main() {
    ll n;
    cin >> n;
    ll l, t;
    cin >> l >> t;
    ll BeforeX[100050];
    ll AfterX[100050];
    ll w[100050];
    vector<ll> SortedAfterX;
    for(int i = 1; i <= n; i++){
        cin >> BeforeX[i] >> w[i];
        if(w[i] == 2) w[i] = -1;
        AfterX[i] = BeforeX[i] + w[i] * t;
        SortedAfterX.push_back((AfterX[i] + (ll)2000000000 * l) % l);
    }
    sort(SortedAfterX.begin(), SortedAfterX.end());
    int start = 0;
    while((((AfterX[1] + (ll)2000000000 * l) % l) != SortedAfterX[start])) start++;
    ll index = 1;
    for(int i = 2; i <= n; i++){
        if(w[1] == w[i]) continue;
        //ll turn = abs(AfterX[i] - AfterX[1] - BeforeX[i] + BeforeX[1]) / l;
        ll turn = Div(AfterX[i] - AfterX[1], l) - Div(BeforeX[i] - BeforeX[1], l);
        //cout << AfterX[i] << " " << AfterX[1] << " " << BeforeX[i] << " " << BeforeX[1] << endl;
        //cout << Div(AfterX[i] - AfterX[1], l) << " " << Div(BeforeX[i] - BeforeX[1], l) << " ";
        index -= turn;
        //cout << i << " " << index << endl;
    }
    index = (index - 1 + n * (ll)1000000000000) % n + 1;
    ll Ans[100050];
    for(int i = 0; i < n; i++){
        Ans[(index + i - 1) % n + 1] = SortedAfterX[(start + i) % n];
    }
    for(int i = 1; i <= n; i++){
        cout << Ans[i] << endl;
    }
    //cout.precision(10);

    return 0;
}
