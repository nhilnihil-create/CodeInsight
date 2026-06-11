#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int a,b,c;
    cin >> a >> b >> c;
    int c1 = max(max(a,b),c);
    int c2 = a+b+c-c1;
    if(c1==c2) cout << "Yes" << endl;
    else cout << "No" << endl;
}