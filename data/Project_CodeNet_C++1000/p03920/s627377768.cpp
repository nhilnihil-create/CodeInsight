#include<bits/stdc++.h>
using namespace std;

int N;
int main() {
    cin >> N;

    int s = 1, e = N;
    int x;
    while(s <= e) {
        int m = (s + e)>>1;

        if(1LL * m * (m + 1) / 2 >= N) {
            x = m;
            e = m - 1;
        }
        else s = m + 1;
    }

    for(int i = 1; i <= x; i++) {
        if(i == x*(x + 1)/2 - N) continue;
        printf("%d\n", i);
    }
}
