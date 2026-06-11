#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    long x=1, y=1;
    for (int i=0; i<N; i++){
        long T, A, p, q;
        cin >> T >> A;
        p = (x + T - 1)/T;
        q = (y + A -1)/A;
        x = T * max(p, q);
        y = A * max(p, q);
    }

    cout << x + y << endl;
    return 0;
}