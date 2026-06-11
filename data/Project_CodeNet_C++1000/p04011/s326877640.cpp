#include <bits/stdc++.h>

#define mod 1000000007;

using namespace std;

void test(){
    int N,K,X,Y;
    cin >> N >> K >> X >>Y;
    int total = 0;
    if(N<K){
        total = N * X;
        cout << total;
        return;
    }
    total += K * X;

    total += (N-K) * Y;
    cout << total << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    test();
}