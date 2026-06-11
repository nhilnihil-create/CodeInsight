#include <bits/stdc++.h>
using namespace std;
#define FO(i,a,b) for (int i = (a); i < (b); i++)

int m4(int c) {
    return ((c%4)+4)%4;
}

int H, W, d;
char col[4] = {'R', 'Y', 'G', 'B'};
int main() {
    scanf ("%d %d %d", &H, &W, &d);
    if (d%2) {
        FO (i,0,H) {
            FO (j,0,W) {
                printf ("%c", col[(i+j)%2]);
            }
            printf ("\n");
        }
        return 0;
    }
    FO (i,0,H) {
        FO (j,0,W) {
            int c1 = i+j;
            int c2 = j-i+1000;
            int c = ((c1/d)+(c2/d)*2)%4;
            printf ("%c", col[c]);
        }
        printf ("\n");
    }
    return 0;
}
