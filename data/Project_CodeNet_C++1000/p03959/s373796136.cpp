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
long long slow_mult(long long base, long long exp, long long mod = MOD) {
    long long tot = 0;
    for(;exp > 0;exp >>= 1) {
       if((exp & 1) == 1) tot = (tot + base) % mod;
       base = (base + base) % mod;
    }
    return tot;
}

unsigned long long pre[100005], suf[100005], conf[100005];

int main(){

    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;

    for(int i = 0; i < n; ++i)
        cin >> pre[i];
    for(int i = 0; i < n; ++i)
        cin >> suf[i];

    unsigned long long prod = 1;

    for(int i = 0; i < n; ++i){
        conf[i] = -1;
        if(i == 0 || pre[i] != pre[i - 1]){
            conf[i] = pre[i];
            if(conf[i] > suf[i]){
                cout << "0\n";
                return 0;
            }
        }
    }

    for(int i = n - 1; i >= 0; --i){
        if(i == n - 1 || suf[i] != suf[i + 1]){
            if(conf[i] != -1 && conf[i] != suf[i]){
                cout << "0\n";
                return 0;
            }
            conf[i] = suf[i];
            if(conf[i] > pre[i]){
                cout << "0\n";
                return 0;
            }
        }
    }

    if(pre[n - 1] != suf[0]){
        cout << "0\n";
        return 0;
    }

    bool opp = false;

    for(int i = 0; i < n; ++i){
        if(opp == false){
            if(pre[i] >= suf[i])
                opp = true;
        } else {
            if(pre[i] < suf[i]){
                cout << "0\n";
                return 0;
            }
        }
    }

    opp = false;

    for(int i = n - 1; i >= 0; --i){
        if(opp == false){
            if(pre[i] <= suf[i])
                opp = true;
        } else {
            if(pre[i] > suf[i]){
                cout << "0\n";
                return 0;
            }
        }
    }


    for(int i = 0; i < n; ++i){
        if(conf[i] != -1) continue;
        prod = slow_mult(prod, min(pre[i], suf[i]));
    }

    cout << prod << "\n";

    return 0;

}
