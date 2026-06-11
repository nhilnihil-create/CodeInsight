#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    ll a,b;
    cin >> a >> b;
    if(a > 0 && b > 0){
        cout << "Positive" << endl;
    }
    else if(a < 0 && b < 0){
        int size = abs(a) - abs(b) + 1;
        if(size %2 == 0) cout << "Positive" << endl;
        else cout << "Negative" << endl;
    }
    else{
        cout << "Zero" << endl;
    }
}