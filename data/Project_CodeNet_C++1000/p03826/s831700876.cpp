#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a,b,c,d;
    cin >> a >> b >> c >> d;
    long long ab = a*b;
    long long cd = c*d;
    cout << max(ab,cd) << endl;
}