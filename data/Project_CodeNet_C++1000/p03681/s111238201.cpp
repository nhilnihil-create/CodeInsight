#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll pow(ll n){
    if(n == 1) return 1;
    else return n*pow(n-1)%1000000007;
}

int main(){
    ll n,m;
    cin >> n >> m;
    if(abs(n-m)>1){
        cout << "0" << endl;
        return 0;
    }
    if(n==m)cout << 2*pow(n)*pow(m)%1000000007 << endl;
    else cout << pow(n)*pow(m)%1000000007 << endl;

}