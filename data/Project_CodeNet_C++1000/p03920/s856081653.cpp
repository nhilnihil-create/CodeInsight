#include <iostream>
#include <limits.h>
using namespace std;

int main(void){
    long long n, k = 0;
    cin >> n;
    while ((k * (k + 1)) / 2 < n) k++;
    for (int i = 1; i <= k; i++) {
        if ((k * (k + 1)) / 2 - n != i) cout << i << endl;
    }
}
