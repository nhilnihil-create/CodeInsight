/**
 *   @FileName	a.cpp
 *   @Author	kanpurin
 *   @Created	2020.08.11 02:49:45
**/

#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;

int main() {
    int n;cin >> n;
    vector<int> b(n,0);
    int nax = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        nax = max(nax,a);
        b[a]++;
    }
    if (b[nax] < 2) {
        puts("Impossible");
    }
    else if (nax % 2 == 0) {
        int k = nax / 2;
        if (b[k] != 1) puts("Impossible");
        else {
            for(int i = k + 1; i < nax; i++) {
                if (b[i] < 2) {
                    puts("Impossible");
                    return 0;
                }
            }
            puts("Possible");
        }
    }
    else {
        int k = nax / 2 + 1;
        if (b[k] != 2) puts("Impossible");
        else {
            for(int i = k + 1; i < nax; i++) {
                if (b[i] < 2) {
                    puts("Impossible");
                    return 0;
                }
            }
            puts("Possible");
        }
    }
    return 0;
}
