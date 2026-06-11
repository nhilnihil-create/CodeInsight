#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < m+1; j++) {
            if(m*i+(n-i)*j-i*j==k){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    

    return 0;
}