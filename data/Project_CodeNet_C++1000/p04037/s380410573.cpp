#include "bits/stdc++.h"
using namespace std;

int main() {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
        sort(a.rbegin(), a.rend());
        int h = 0, w = 0;
        while (true) {
                if (a[w] <= h) break;
                h ++, w ++;
        }
        h --, w --;
        int res1 = a[w] - h - 1;
        int k = w;
        while (h < a[k]) k ++;
        int res2 = k - w - 1;
        puts((res1 & 1 || res2 & 1) ? "First" : "Second");
        return 0;
}
