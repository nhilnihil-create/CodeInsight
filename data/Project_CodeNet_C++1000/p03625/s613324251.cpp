#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    long long a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    unsigned long long  p = 0,q = 0;
    for(int i = 1;i < n; i++ ){
        if(a[i-1] == a[i]){
            p = q;
            q = a[i];
            a[i-1] = 0;
            a[i] = 0;
        }
    }
    cout << p*q << endl;

    return 0;
}