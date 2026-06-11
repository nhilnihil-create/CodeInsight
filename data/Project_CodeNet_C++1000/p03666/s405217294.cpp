#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    long long k = d - c;
    for(int i=0; i<=n-1; i++){
        long long j = n - 1 - i;
        long long e = b - (a + c*(i-j));
        if(-k*j <= e && e <= k*i){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
