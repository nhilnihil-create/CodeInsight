#include <bits/stdc++.h>
using namespace std;
#define N (int)4e5
typedef long long ll;
vector<ll> v;
ll maxim[N],minim[N],n;

void preCompute() {
    priority_queue<ll> pQ;
    ll sum = 0;
    for (int i = (3 * n) - 1 ; i >= 0 ; i--) {
        pQ.push(v[i]);
        sum += v[i];
        if ((int)pQ.size() > n) {
            sum -= pQ.top();
            pQ.pop();
        }
        minim[i] = sum;
    }
    while (!pQ.empty()) pQ.pop();
    sum = 0;
    for (int i = 0 ; i < 3 * n ; i++) {
        pQ.push(-v[i]);
        sum += v[i];
        if ((int)pQ.size() > n) {
            sum += pQ.top();
            pQ.pop();
        }
        maxim[i] = sum;
    }
}

int main() {
    scanf("%lld" , &n);
    v.resize(3 * n);
    for (int i = 0 ; i < 3 * n ; i++)
        scanf("%lld" , &v[i]);
    preCompute();
    ll sol = LLONG_MIN;
    for (int i = n - 1 ; i < (2 * n) ; i++)
        sol = max(sol , maxim[i] - minim[i + 1]);
    printf("%lld\n" , sol);
}
