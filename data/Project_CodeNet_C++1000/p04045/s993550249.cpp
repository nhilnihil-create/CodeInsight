#include <bits/stdc++.h>
using namespace std;

int main(){
    int m;
    int n;
    int a[10], b;

    cin >> m;
    cin >> n;

    for (int i = 0; i < 10; i++){
        a[i] = 0;
    }

    for (int i = 0; i < n; i++){
        cin >> b;
        a[b]++;
    }

    for (int i = m; i < 100000; i++){
        b = i;
        while (b != 0){
            if (a[b % 10] != 0){
                break;
            }
            b /= 10;
        }
        if (b == 0){
            printf("%d", i);
            return 0;
        }
    }
}