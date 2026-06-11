#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
vector<int> A;

int main() {
    scanf("%d", &N);
    A.resize(N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int mn = 2;
    ll ans = (A[0] - 1);
    for(int i = 1; i < N; i++) {
        if(A[i] == mn) {
            mn++;
            continue;
        }
        ans += (A[i] - 1) / mn;
    }

    cout << ans;
}
