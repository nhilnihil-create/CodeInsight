#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pf push_front
#define pb push_back
deque<int> A, B;
LL n;
int now = 1;

void work(LL x) {
    if (x == 1) return; else work(x / 2);
    A.pf(++now), B.pf(now);
    if (x & 1) A.pf(++now), B.pb(now);
}
 
int main() {
    cin >> n;
    work(n + 1);
    printf("%d\n", A.size() + B.size());
    for(int i = 0; i < A.size(); i++) printf("%d ", A[i]);
    for(int i = 0; i < B.size(); i++) printf("%d ", B[i]);
}