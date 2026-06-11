#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,p;
    cin >> n >> p;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] = a[i] % 2;
    }
    int odd = 0, even = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            even++;
        }else{
            odd++;
        }
    }
    if(even == n){
        if(p == 0){
            cout << (ll)pow(2,n) << endl;
        }else{
            cout << 0 << endl;
        }
    }else{
        cout << (ll)pow(2,n-1) << endl;
    }
    
    return 0;
}



