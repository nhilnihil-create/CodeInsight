#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int a,b;
    cin >> a >> b;
    if((a < 0 && b < 0 && a%2 != b%2) || (a > 0 && b > 0)) cout <<  "Positive" << endl;
    else if(a < 0 && b < 0 && a%2 == b%2) cout << "Negative" << endl;
    else cout << "Zero" << endl;
    return 0;  
}