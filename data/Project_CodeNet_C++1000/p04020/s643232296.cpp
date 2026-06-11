#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    long long int ans = 0;
    long long int count = 0;
    for(int i=0; i<n; i++){
        if(a[i] != 0) count += a[i];
        if(a[i] == 0 || i == n-1){
            ans += count / 2;
            count = 0;
        }
    }
    cout << ans << endl;
    return 0;
}