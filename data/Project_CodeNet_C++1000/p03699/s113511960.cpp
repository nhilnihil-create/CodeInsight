#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n, sum = 0, re = 100;
    cin >> n;
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        sum += m;
        if(m%10 != 0 && m <= re) re = m;
    }
    if(re == 100) re = sum;
    if(sum%10 == 0) cout << sum - re << endl;
    else cout << sum << endl;
}