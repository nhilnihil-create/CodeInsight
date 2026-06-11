#include <bits/stdc++.h>
#define ll long long


using namespace std;

const int MAXN = (int) 1e5;

pair <int, int> v[MAXN + 1];

vector <bool> bits;

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(i = 1; i <= n; i++)
        cin >> v[i].first >> v[i].second;
    int aux = k;
    while(aux > 0) {
        bits.push_back(aux & 1);
        aux >>= 1;
    }
    ll ans = 0;
    for(i = 0; i <= bits.size(); i++) {
        ll sum = 0;
        for(int p = 1; p <= n; p++) {
            if(v[p].first <= k) {
                bool flag = 1;
                for(j = (int) bits.size() - 1; j >= (int) bits.size() - i; j--) {
                    if(bits[j] < ((v[p].first & (1 << j)) > 0))
                        flag = 0;
                }
                while(j >= 0 && bits[j] == 0) {
                    if(v[p].first & (1 << j))
                        flag = 0;
                    j--;
                }
                if((j >= 0 && (v[p].first & (1 << j)) == 0) || j == -1)
                    sum += v[p].second * flag;
            }
        }
        ans = max(ans, sum);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}
