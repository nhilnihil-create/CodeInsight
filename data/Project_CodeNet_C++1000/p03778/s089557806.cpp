#include <bits/stdc++.h>
using namespace std;

int main(){ 
    int w,a,b;
    cin >> w >> a >> b;
    if(b > a+w) cout << b-(a+w) << endl;
    else if(a > b+w) cout << a-(b+w) << endl;
    else cout << 0 << endl;
 }