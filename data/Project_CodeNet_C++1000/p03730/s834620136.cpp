#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    
    if(c>0) {
    if(a%b ==0) {
     cout << "NO";
    } else if(a%2 == 0 && b%2 !=0){
        cout << "NO";
    } else if(c%gcd(a,b)) {
        cout << "NO";
    }        else {
     cout << "YES";
    }
    }
    
    else {
     cout << "YES";
    }
    
    
    }
