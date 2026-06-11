#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int m = 0, ans = 0;
    for(int x : a){
        m += x;
    }
    if((m*10 / n) % 10 >= 5)m = m / n + 1;
    else m = m / n;
    for(int x : a){
        ans += pow(x - m, 2);
    }
    cout << ans << endl;
}