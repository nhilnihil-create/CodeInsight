#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;

void solve();

int main(void){
    int N;
    int nosolve = -1;
    int upplim = -1;
    int index = 1;
    cin >> N;
    while(N >= 0){
        N -= index;
        index++;
    }
    nosolve = abs(N);
    for(int i = 1; i < index; i++){
        if(i != nosolve) printf("%d\n", i);
    }

    return 0;
}

void solve(){}