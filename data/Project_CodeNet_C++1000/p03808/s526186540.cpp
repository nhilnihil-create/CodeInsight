#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n;
    cin >> n;

    long long int sum = 0;
    vector<long long int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum += a[i];
    }

    long long int div = n * (n+1) / 2;
    if(sum % div != 0){
        cout << "NO" << endl;
        return 0;
    }

    long long int times = sum / div;
    long long int count = 0;
    long long int memo = 0;

    for(int i=1; i<n; i++){
        long long int diff = (a[i-1] + times) - a[i];
        if(diff < 0 || diff % n != 0){
            cout << "NO" << endl;
            return 0;
        }
        count += diff / n;
        memo += (n+1 - i) * (diff / n);
    }
    if(count > times) cout << "NO" << endl;
    else if(memo + (times - count) != a[0]) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}