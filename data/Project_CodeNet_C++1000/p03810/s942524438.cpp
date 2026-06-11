#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5+10;

int n;
int niz[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", niz+i);

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += 1 - (niz[i] % 2);
    }

    if (cnt == n) printf("First\n");
    else if (cnt % 2 == 1) printf("First\n");
    else {
        if (n - cnt > 1) printf("Second\n");
        else {
            bool turn = true;
            int maxi = *max_element(niz, niz+n);
            while (maxi > 1) {
                int ind = -1;
                for (int i = 0; i < n; i++)
                    if (niz[i] % 2 == 1 && niz[i] > 1) ind = i;

                if (ind == -1) break;
                niz[ind]--;

                int gc = niz[0];
                for (int i = 1; i < n; i++)
                    gc = __gcd(gc, niz[i]);

                maxi = -1;
                int cnt = 0;
                for (int i = 0; i < n; i++) {
                    niz[i] /= gc, maxi = max(maxi, niz[i]);
                    cnt += 1 - (niz[i] % 2);
                }
                if (cnt % 2 == 1) break;
                else if (n - cnt > 1) {
                    turn = !turn;
                    break;
                }
                turn = !turn;
            }

            if (turn) printf("Second\n");
            else printf("First\n");
        }
    }
    return 0;
}
