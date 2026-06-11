#include <bits/stdc++.h>
using namespace std;

int main(){
    int x,a,b;
    cin >> x >> a >> b;
    char ans;
    ans = (abs(x-a) < abs(x-b) ? 'A' : 'B');
    cout << ans << endl;
}