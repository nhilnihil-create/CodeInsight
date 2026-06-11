#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n, x;
    cin >> n >> x;
    long long a[n];
    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }

    long long count = 0;
    for(long long i = 0; i < n-1; i++){
        if(a[i] + a[i+1] > x){
            long long delta = a[i] + a[i+1] - x;
            count += delta;
            if(a[i+1] - delta >= 0){
                a[i+1] -= delta;
            }
            else{
                delta -= a[i+1];
                a[i+1] = 0;
                a[i] -= delta;
            }
        }
    }

    cout << count << endl;
    return 0;
}