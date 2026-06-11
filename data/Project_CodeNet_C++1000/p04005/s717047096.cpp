#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a[3];
    cin >> a[0] >> a[1] >> a[2];
    if(a[0]%2==0||a[1]%2==0||a[2]%2==0){
        cout << 0 << endl;
        return 0;
    }else{
        sort(a,a+3);
        cout << a[0]*a[1] << endl;
        return 0;
    }
}