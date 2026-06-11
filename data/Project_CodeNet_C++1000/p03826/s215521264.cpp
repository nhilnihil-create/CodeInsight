#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int n = a*b;
    int m = c*d;

    if(n > m){
        cout << n << endl;
    }
    else cout << m << endl;
    
    return 0;
}