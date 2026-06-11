#include <bits/stdc++.h>
using namespace std;

int main(){

    int N, K;
    cin >> N >> K;

    long long cnt = 0, buf = K;
    cnt += buf;

    for(int i=1; i<N; i++){
        buf = K - 1;
        cnt *= buf;
    }

    cout << cnt << endl;
    return 0;
}