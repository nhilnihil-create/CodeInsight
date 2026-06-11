#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    cout << (n<=k ? n*x : k*x + (n-k)*y) << endl;
    return 0;
}