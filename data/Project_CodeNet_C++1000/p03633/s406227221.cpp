#include <iostream>
#include <cstdio>
using namespace std;

long long gcd(long long x, long long y){
    if(y == 0){
        return x;
    }

    return gcd(y, x%y);
}

long long lcm(long long x, long long y){
    return x/gcd(x,y)*y;
}

int main(){
    long long n;
    cin >> n;

    long long T[n];

    for(long long i = 0; i < n; i++){
        cin >> T[i];
    }

    long long ans = T[0];
    for(long long i = 1; i < n; i++){
        ans = lcm(ans, T[i]);
    }

    cout << ans << endl;

    
    return 0;
}