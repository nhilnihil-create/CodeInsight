#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        --a[i];
    }

    for(int c = 0, now = 0; true; c++){
        if(now == 1){
            cout << c << endl;
            break;
        }

        if(c >= n){
            cout << -1 << endl;
            break;
        }
        
        now = a[now];
    }
}