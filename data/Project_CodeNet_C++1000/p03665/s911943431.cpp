#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

vector<ll> combi_even(51, 0);
vector<ll> combi_odd(51, 0);

void bfs_even(int i, int n) {
    if (i == n) {
        combi_even[i] = 1;
        return;
    }
    combi_even[i+1] = combi_even[i]*(n-i)/(i+1);
    bfs_even(i+1, n);
}
void bfs_odd(int i, int n) {
    if (i == n) {
        combi_odd[i] = 1;
        return;
    }
    combi_odd[i+1] = combi_odd[i]*(n-i)/(i+1);
    bfs_odd(i+1, n);
}

int main() {
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    int cnt_even=0, cnt_odd=0;
    rep(i, n) {
        cin >> a[i];
        if (a[i]%2==0) {
            cnt_even++;
        }
        else {
            cnt_odd++;
        }
    }
    combi_even[0] = 1;
    combi_odd[0] = 1;
    bfs_even(0, cnt_even);
    bfs_odd(0, cnt_odd);
    ll out_even = 0;
    ll out_odd = 0;
    rep(i, cnt_even+1) out_even += combi_even[i];
    rep(i, cnt_odd+1) {
        if (p==0 && i%2 == 0) {
            out_odd += combi_odd[i];
        }
        else if (p==1 && i%2 == 1) {
            out_odd += combi_odd[i];
        }
    }
    cout << out_even * out_odd << endl;


    return 0;
}