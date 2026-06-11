#include <bits/stdc++.h>
using namespace std;

int main(void){
    int H, W;
    vector<string> a(100);

    cin >> H >> W;
    for(int i = 0; i < H; i++){
        cin >> a[i];
    }

    for(int i = 0; i < W + 2; i++){
        putchar('#');
    }
    putchar('\n');

    for(int i = 0; i < H; i++){
        putchar('#');
        cout << a[i];
        putchar('#');
        putchar('\n');
    }

    for(int i = 0; i < W + 2; i++){
        putchar('#');
    }
    putchar('\n');

    return 0;
}

