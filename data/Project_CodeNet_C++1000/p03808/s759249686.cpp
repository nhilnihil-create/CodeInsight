#include <bits/stdc++.h>

using namespace std;

long long n, a[100005], sum = 0, b[100005];

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum %( n * (n + 1) / 2) != 0){
        cout << "NO\n";
        return 0;
    }
    long long num = sum / (n * (n + 1) / 2);
    for(int i = 0; i < n; i++){
        b[i] = -a[(i + 1)%n] + a[i] + num;
        if(b[i] >= 0 && b[i] % n == 0){

        }
        else{
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}