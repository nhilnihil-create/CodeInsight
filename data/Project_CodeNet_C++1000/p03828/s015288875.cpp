#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define Rep(i, n) for (int i = 0; i < (int)(n); i++)
#define BitRep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define All(vec) vec.begin(), vec.end()
#define Sum(vec) accumulate(vec.begin(), vec.end(), 0)
#define Sort(vec) sort(vec.begin(), vec.end())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Next_permutation(vec) next_permutation(vec.begin(), vec.end())
#define PI acos(-1)

vector<int> prime;

bool isprime(int N) {
    if (N == 2) return true;
    else if (N % 2 == 0) return false;
    else if (N == 1) return false;
    for (int i = 3; i <= sqrt(N); i++) {
        if (N % i == 0)return false;
    }
    return true;
}

void factorial(int N, vector<int>& cnt) {
    int i = 0;
    while (!isprime(N)) {
        int p = prime[i];
        if (N % p == 0) {
            cnt[p]++;
            N /= p;
        }
        else i++;
    }
    if (isprime(N)) cnt[N]++;
}

int main() {
    int N;
    cin >> N;
    vector<int> cnt(N + 1);
    Rep(i, N + 1) {
        if (isprime(i)) prime.push_back(i);
    }
    for (int i = 2; i <= N; i++) factorial(i, cnt);
    ll ans = 1;
    for (int i = 0; i < prime.size(); i++) {
        if (cnt[prime[i]] >= 1) {
            ans *= cnt[prime[i]] + 1;
            ans %= 1000000007;
        }
    }
    cout << ans << endl;
    return 0;
}