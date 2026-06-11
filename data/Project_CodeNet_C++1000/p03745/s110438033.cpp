#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, ret = 1, bef, pmz = 0;
    scanf("%d", &n);
    scanf("%d", &a); bef = a;
    for (int i = 1; i < n; i++) {
        if (pmz == 0) {
            if (bef == a) {
                // do nothing
            } else if (bef > a) {
                pmz = -1;
            } else { // bef < a
                pmz = 1;
            }
        } else {
            if (bef == a) {
                // do nothing
            } else if (bef > a) {
                if (pmz != -1) {pmz = 0; ret++;}
            } else { // bef < a
                if (pmz != 1) {pmz = 0; ret++;}
            }
        }
        bef = a;
        scanf("%d", &a);
    }

    if (pmz ==  0 &&  (bef == a) && n != 1) ret++; // for subtask_1_10.txt
    if (pmz ==  1 && !(bef <= a)) ret++;
    if (pmz == -1 && !(bef >= a)) ret++;

    printf("%d\n", ret);
    return 0;
}