#include <bits/stdc++.h>
using namespace std;
 
/*
Nの階乗の10^9+7のあまりを求める問題。
i=n-1のとき、
(n-1)! = p * (10^9+7) + c
cはあまり。
 
i = nのとき、
n * (n-1)! = n * p * (10^9+7) + n * c
 
よってn!のあまりは、n * cを(10^9+7)でわったときのあまりを計算すればよい。
したがったあまりはそのつど計算できる。
*/
 
int main() {
    int N;
    cin >> N;
 
    long dev = 1e9 + 7;
    long mod = 1;
    for (int i = 1; i <= N; i++)
    {
        mod = mod * i % dev;
    }
    cout << mod << endl;
}