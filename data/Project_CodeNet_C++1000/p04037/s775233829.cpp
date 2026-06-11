#include "bits/stdc++.h"
using namespace std;

int main() {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
        sort(a.rbegin(), a.rend());
        int h = 0, w = 0;
        while (a[w] > h) h ++, w ++;
        h --, w --;
        int k = w;
        while (h < a[k]) k ++;
        puts(((a[w] - h - 1) & 1 || (k - w - 1) & 1) ? "First" : "Second");
        return 0;
}
