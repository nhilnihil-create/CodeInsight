#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

int main() {
    string a,b,c;
    cin>>a>>b>>c;
    string s = {a[0],b[0],c[0]};
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout<<s<<endl;
    
}

