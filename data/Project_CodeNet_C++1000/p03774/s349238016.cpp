#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;

    long long a[n], b[n], c[m], d[m];

    for(long long i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }

    for(long long i = 0; i < m; i++){
        cin >> c[i] >> d[i];
    }

    long long check[n];

    long long min;
    for(long long i = 0; i < n; i++){
        min = 1e9;
        for(long long j = 0; j < m; j++){
            if(min > abs(a[i] - c[j]) + abs(b[i] - d[j])){
                min = abs(a[i] - c[j]) + abs(b[i] - d[j]);
                check[i] = j;
            }
        }
    }

    for(long long i = 0; i < n; i++){
        printf("%lld\n", check[i]+1);
    }

    return 0;
}