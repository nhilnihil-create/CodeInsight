#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n,a,b;
    cin >> n >> a >> b;
    if(b-a < 0 || (n == 1 && a != b)){
        cout << 0 << endl;
        return 0;
    }
    if(n == 1 && a == b){
        cout << 1 << endl;
        return 0;
    }

    if(n >= 2){
        cout << (b-a)*(n-2) + 1 << endl;
    }
    return 0;
}