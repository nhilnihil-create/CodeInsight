#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long h, w;
    cin >> h >> w;
    vector<vector<char> > a(h, vector<char>(w));
    vector<vector<char> > ans(h+2, vector<char>(w+2, '#'));

    for(long long i = 0; i < h; i++){
        for(long long j = 0; j < w; j++){
            cin >> a[i][j];
        }
    }

    for(long long i = 1; i <= h; i++){
        for(long long j = 1; j <= w; j++){
            ans[i][j] = a[i-1][j-1];
        }
    }

    for(long long i = 0; i < h+2; i++){
        for(long long j = 0; j < w+2; j++){
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}