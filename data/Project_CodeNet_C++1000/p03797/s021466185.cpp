#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,m;
    cin>>n>>m;
    if (n<m) {
        m/=2;
        n+=m;
        cout<<n/2<<endl;
    } else {
        cout<<m/2<<endl;
    }
}