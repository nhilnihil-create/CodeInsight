#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,x;
    cin >> n >> x;
    if(x==1 || x==2*n-1) cout << "No" << endl;
    else if(x < n){
        cout << "Yes" << endl;
        for(int i=n; i>0; i--){
            if(i == x)continue;
            cout << i << ' ';
        }
        cout << x << ' ';
        for(int i = n+1; i<2*n; i++){
            cout << i << ' ';
        }
        cout << endl;
    }
    else if(x == n){
        cout << "Yes" << endl;
        for(int i=1; i<=2*n-1; i++){
            cout << i << ' ';
        }
        cout << endl;
    }
    else {
        cout << "Yes" << endl;
        for(int i=1; i<n; i++){
            cout << i << ' ';
        }
        cout << x << ' ';
        for(int i=2*n-1; i>=n; i--){
            if(i == x) continue;
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}
