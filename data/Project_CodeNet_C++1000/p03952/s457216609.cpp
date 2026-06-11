/**
 *   @FileName	a.cpp
 *   @Author	kanpurin
 *   @Created	2020.08.17 19:02:25
**/

#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;

int main() {
    int n,x;cin >> n >> x;
    if (x == 1 || x == 2 * n - 1) {
        puts("No");
        return 0;
    }
    puts("Yes");
    for (int i = 0; i < 2 * n - 1; i++) {
        cout << (i+x+n-1) % (2 * n - 1) + 1 << endl;
    }
    return 0;
}