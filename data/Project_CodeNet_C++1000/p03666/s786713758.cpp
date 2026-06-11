#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, a, b, c, d;

    cin >> n >> a >> b >> c >> d;

    long long sa = 2*c;

    long long haba = d-c;
    for(int i = 0;i < n-2;i++){
        sa -= (d - c);
        haba += (d - c);
        if(sa <= 0){
            sa = 0;
            break;
        }
    }

    long long ma = d*(n-1)+a;
    for(int i = 0;i < n;i++){
        if(ma-haba <= b && b <= ma){
            cout <<"YES" << endl;
            return 0;
        }
        ma -= haba+sa;
    }

    cout << "NO" << endl;
    return 0;
}




