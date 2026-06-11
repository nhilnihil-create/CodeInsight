#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

int main() {
    int n;
    cin >> n;
    if(n % 10 == 9){
        cout << "Yes" << endl;
    }else if(n/10 == 9){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}

