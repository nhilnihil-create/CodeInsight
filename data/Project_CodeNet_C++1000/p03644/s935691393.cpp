#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

long long two_count(long long n){
    long long cnt = 0;

    while(n % 2 == 0){
        cnt++;
        n /= 2;
    }
    return cnt;
}

int main(){
    long long n;
    cin >> n;
    vector<long long> a(101, 0);

    for(long long i = 1; i <= n; i++) a[i] = two_count(i);

    long long maxv = 0;

    for(long long i = 1; i <= n; i++) maxv = max(maxv, a[i]);

    long long number;
    for(long long i = 1; i <= n; i++) if(maxv == a[i]) number = i;

    cout << number << endl;
    return 0;
}