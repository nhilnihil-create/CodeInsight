#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

int main(){
    long long n;
    cin >> n;

    long long a = 0;
    long long b = 0;

    for(long long i=1; i*i <= n; i++){
        if(n%i == 0){
            a = i;
            b = n/i;
        }
    }

    long long lena = 0;
    long long lenb = 0;

    while(a > 0){
        a /= 10;
        lena ++;
    }
    while(b > 0){
        b /= 10;
        lenb ++;
    }

    cout << max(lena,lenb) << endl;

}