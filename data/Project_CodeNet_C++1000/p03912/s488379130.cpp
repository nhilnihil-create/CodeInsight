#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007LL;
long long GCD(long long a, long long b){return b == 0 ? a : GCD(b, a % b);}
long long fast_exp(long long base, long long exp, long long mod = MOD) {
    long long tot = 1;
    for(;exp > 0;exp >>= 1) {
       if((exp & 1) == 1) tot = tot * base % mod;
       base = base * base % mod;
    }
    return tot;
}

int freq[100005], rem[100005];
vector<int> nums[100005];

int main(){

    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m, a; cin >> n >> m;

    // greedy match between the two

    for(int i = 0; i < n; ++i){
        cin >> a;
        if(freq[a] == 0){
            nums[a % m].push_back(a);
        }
        ++freq[a]; ++rem[a % m];
    }

    long long tot = rem[0] / 2;

    if(m % 2 == 0)
        tot += rem[m / 2] / 2;

    for(int i = 1; i + i < m; ++i){
        int a = i, b = m - i;
        if(rem[a] < rem[b]){
            int sw = a;
            a = b; b = sw;
        }
        for(int j : nums[a]){
            if(rem[a] - 2 < rem[b]) break;
            while(rem[a] - 2 >= rem[b] && freq[j] > 1){
                freq[j] -= 2;
                ++tot;
                rem[a] -= 2;
            }
        }
        tot += min(rem[a], rem[b]);
    }

    cout << tot << "\n";

    return 0;

}
