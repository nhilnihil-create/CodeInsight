#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

int main(){
    int x,a,b;
    cin >> x >> a >> b;
    if(a-b >= 0) cout << "delicious" << endl;
    else if(b-a-x > 0) cout << "dangerous" << endl;
    else cout << "safe" << endl;     
}