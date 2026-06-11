#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n,a=1,MOD;
    cin >> n;
    MOD = 1000000007;
    for(int i=1;i<n+1;i++){
        a%=MOD;
        a*=i;
        a%=MOD;
    }
    cout << a << endl;



}