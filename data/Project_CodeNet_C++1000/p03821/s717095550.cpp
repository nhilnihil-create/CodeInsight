#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n;
    cin >> n;

    long long a[n+1], b[n+1];

    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
    }

    long long button = 0;

    for(int i = n; i >= 1; i--){
        if((a[i]+button) % b[i] == 0){
            continue;
        }
        long long amari = (a[i]+button) % b[i];
        button += (b[i]-amari);
    }

    printf("%lld\n", button);
}