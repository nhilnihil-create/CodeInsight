#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n, x;
    cin >> n >> x;
    
    vector<long long> a(n);
    
    for (int i = 0; i < n; i++) cin >> a[i];
    
    long long count = 0;
    
    if (a[0] > x) count += (a[0]- x), a[0] = x;
    
    for (int i = 0; i +1 < n; i++){
        
        if (a[i] + a[i+1] > x){
            count += (a[i] + a[i+1] - x);
            a[i+1] = x - a[i];
        }
    }
    cout << count << endl;
    
}
