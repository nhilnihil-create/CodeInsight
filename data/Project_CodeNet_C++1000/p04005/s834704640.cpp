#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    unsigned long long a[3],b,c;
    cin >> a[0] >> a[1] >> a[2];
    sort(a,a+3);    
    if(a[0] % 2 == 0 || a[1] % 2 == 0 || a[2] % 2 == 0){
        cout << 0 << endl;
    }else{
        cout << a[0]*a[1] << endl;
    }
    return 0;
}
