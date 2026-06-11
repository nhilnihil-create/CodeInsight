#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long x;
    cin >> x;
    if(x%11 == 0) cout << x/11*2 << endl;
    else if(x%11 <=6) cout << x/11*2 + 1 << endl;
    else cout << x/11*2 + 2 << endl;
}
