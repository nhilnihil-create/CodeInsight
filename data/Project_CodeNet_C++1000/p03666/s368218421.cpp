#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    for (int i = 0; i < n; i++){
        if (c * (n - 1 - i) - d * i <= b - a && b - a <= d * (n - 1 - i) - c * i){
            cout << "YES" << endl;
            exit(0);
        }
    }
    cout << "NO" << endl;
}