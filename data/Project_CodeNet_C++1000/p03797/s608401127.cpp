#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    unsigned long long  n,m;
    cin >> n >> m;
    if(m <= n*2){
        cout << m/2 << endl;
    }else{
        cout << n + (m-n*2)/4 << endl;
    } 
    return 0;
}