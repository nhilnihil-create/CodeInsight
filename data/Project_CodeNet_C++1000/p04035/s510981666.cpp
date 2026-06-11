#include <bits/stdc++.h>

using namespace std;

int n;
long long L, a[100005];

int main() {
    int id = 0;
    cin >> n >> L;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++) {
        if(a[i] + a[i + 1] >= L) id = i;
    }
    if(id == 0) return printf("Impossible\n"), 0;
    printf("Possible\n");
    for(int i = 1; i < id; i++) printf("%d\n", i);
    for(int i = n - 1; i > id; i--) printf("%d\n", i);
    printf("%d\n", id);
    return 0;
}

//09:08:00