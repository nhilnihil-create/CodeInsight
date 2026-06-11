#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n, x;
    cin >> n >> x;

    long long int a = n-x;
    long long int b = x;
    if(a < b) swap(a,b);
    
    long long int ans = 0;
    while(b != 0){
        ans += (a / b) * 3 * b;
        a %= b;
        swap(a,b);
    }
    cout << ans << endl;
    return 0;
}