#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,t;
    cin >> n >> t;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    long long count = t;
    for(int i = 0; i < n-1; i++){
        count += min(a[i+1]-a[i],t);
    }
    cout << count << endl;
    return 0;
}