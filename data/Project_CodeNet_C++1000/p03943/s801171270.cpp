#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a+b == c || b+c == a || c+a == b) cout << "Yes" << endl;
    else cout << "No" << endl;    
}