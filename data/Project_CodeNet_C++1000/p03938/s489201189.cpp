#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    vector<int> p(N);
    for (int i = 0; i < N; i++) cin >> p[i];
    vector<int> a(N+2, 0), b(N+2, 0);
    
    for (int i = 1; i < N; i++) {
        a[p[i]] += i;
        b[p[i]] += i;
    }
    for (int i = 1; i <= N; i++) {
        a[i] += a[i-1];
    }
    for (int i = N; i >= 1; i--) {
        b[i] += b[i+1];
    }
    for (int i = 1; i <= N; i++) {
        if (i < N) printf("%d ", a[i]+i);
        else printf("%d\n", a[i]+i);
    }
    for (int i = 1; i <= N; i++) {
        if (i < N) printf("%d ", b[i]+N+1-i);
        else printf("%d\n", b[i]+N+1-i);
    }
}
