#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MAX 100001
int A[MAX];
vector<int> v[MAX];

void dfs(int root, int parent) {
    if(v[root].size() == 1) return;

    ll mx = -1, sum = -A[root];
    for(int vv : v[root]) {
        if(vv != parent) {
            dfs(vv, root);
            sum += A[vv];
            if(mx < A[vv]) mx = A[vv];
        }
    }
    if(sum < 0 || A[root] < mx || (A[root]-=sum) < 0) puts("NO"), exit(0);
}

int main(void) {
    int i, n, a, b, root;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", A+i);
    if(n == 2) return puts(A[0] == 1 && A[1] == 1 ? "YES" : "NO"), 0;
    for(i=0; i<n-1; i++) {
        scanf("%d%d", &a, &b);
        v[a-1].emplace_back(b-1);
        v[b-1].emplace_back(a-1);
    }
    for(root=0; root<n; root++) {
        if(v[root].size() > 1) {dfs(root, -1); break;}
    }
    puts(A[root] ? "NO" : "YES");
    return 0;

}