#include <bits/stdc++.h>
using namespace std;
int main(){
    int K, T;
    cin >> K >> T;
    vector<int> a(T);
    for(int i = 0; i < T; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int t = a[T - 1];
    for(int i = 0; i < T - 1; i++){
        t -= a[i];
    }
    if(t <= 0) cout << 0 << endl;
    else cout << t - 1 << endl;
}