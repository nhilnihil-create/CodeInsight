#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long n;
    cin >> n;

    vector<long long> a(n);
    for(long long i = 0; i < n; i++) cin >> a[i];

    long long ans = 0;
    for(long long i = 0; i < n; i++){
        long long r = a[i]/2;
        ans += r;
        a[i] -= 2*r;
        if(i+1 < n){
            r = (a[i] + a[i+1]) / 2;
            ans += r;
            if(r > 0){
                a[i+1] -= 2 * r - a[i];
            }

        }
    }

    cout << ans << endl;
    return 0;
}