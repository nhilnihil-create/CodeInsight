#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    cout << min(a+b, min(a+c, b+c)) << endl;
}