#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n , a , b, c , d;
    cin >> n >> a >> b >> c >> d;
    if(abs(b - a) > (n - 1) * d){
        cout << "NO";
        return 0;
    }
    for(int i = 1; i <= n; i++){
        long long x = n - i - 1;
        if(a + d * i - c * x >= b && a + c * i - d * x <= b){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
