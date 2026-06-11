#include <bits/stdc++.h>

using namespace std;

int n, a[100005], b[100005], ans = false;

vector <int> L, R;
map <int, int> M;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n + 1);
    reverse(a, a + n + 1);
    for(int i = 0; i <= n; i++) b[i] = a[i] - i - 1;
    L.push_back(0);
    for(int i = 1; i <= n; i++) if(b[i] != b[i - 1] - 1) L.push_back(i);
    for(int i = 0; i < n; i++) if(b[i] != b[i + 1] + 1) R.push_back(i);
    R.push_back(n); // b[L[i]] ~ b[R[i]] ~ b[L[i + 1]] + 2
    for(int i = 0; i < L.size(); i++) M[b[L[i]]] = i;
    auto it = M.lower_bound(0);
    int i = it -> second;
    if(b[R[i]] % 2 == 0) ans = true;
    if(0 == b[L[i + 1]] + 1) {
        if(b[R[i + 1]] % 2 == 0) ans &= true;
        else ans = false;
        //extra_check
    }
    if(ans == false) printf("First\n");
    else printf("Second\n");
    //for(auto x : L) printf("%d ", b[x]); printf("\n");
    //for(auto x : R) printf("%d ", b[x]);
    return 0;
}