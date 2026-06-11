#include<bits/stdc++.h>

using namespace std;
const int N = 212345;

int f1[N],f2[N];

map<pair<int,int>,int>mp;

int Find1(int x) {
    if (x != f1[x]) f1[x] = Find1(f1[x]);
    return f1[x];
}

int Find2(int x) {
    if (x != f2[x]) f2[x] = Find2(f2[x]);
    return f2[x];
}

void Join2(int x,int y) {
    int fx = Find2(x);
    int fy = Find2(y);
    if (fx != fy) {
        f2[fx] = fy;
    }
}

void Join1(int x,int y) {
    int fx = Find1(x);
    int fy = Find1(y);
    if (fx != fy) {
        f1[fx] = fy;
    }
}

int main() {
    int n, k, l;
    scanf("%d%d%d", &n, &k, &l);
    for (int i = 0; i <= n; i++) {
        f1[i] = i;
        f2[i] = i;
    }
    for (int i = 0; i <= k - 1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        Join1(x, y);
    }
    for (int i = 0; i <= l - 1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        Join2(x, y);
    }
    for (int i = 1; i <= n; i++) {
        mp[make_pair(Find1(i), Find2(i))]++;
    }
    for (int i = 1; i <= n; i++) {
        if (i == 1)printf("%d", mp[make_pair(Find1(i), Find2(i))]);
        else printf(" %d", mp[make_pair(Find1(i), Find2(i))]);
    }
    return 0;
}