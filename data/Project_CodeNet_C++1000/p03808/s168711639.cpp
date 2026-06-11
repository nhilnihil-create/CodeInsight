#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin >> n;
    long long a[n];
    long long sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    long long v = (n + 1) * n / 2;
    if(sum % v != 0){
        cout << "NO"; return 0;
    }
    v = sum / v;
    long long x = a[0] - a[n - 1];
    long long k = v - x;
    if(k < 0){
        k = -k;
        k %= n;
        k = n - k;
    }
    if(k % n != 0){
        cout << "NO"; return 0;
    }
    for(int i = 1; i < n; i++){
        long long t = v - a[i] + a[i - 1];
        if(t < 0){
            t = -t;
            t %= n;
            t = n - t;
        }
        if(t % n != 0){
            cout << "NO"; return 0;
        }
    }
    for(int i = 0; i < n; i++){
        if(a[i] < v){
            cout << "NO"; return 0;
        }
    }
    cout << "YES";
}
