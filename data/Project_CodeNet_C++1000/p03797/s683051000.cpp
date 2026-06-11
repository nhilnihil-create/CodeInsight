#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n, m;
    cin >> n >> m;
    if(n < m/2){
        cout << (2*n + m) / 4 << endl;
    }
    else{
        cout << m/2 << endl;
    }
}