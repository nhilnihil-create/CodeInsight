#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll a,b;
    cin >> a >> b;
    if (a * b <= 0){
        cout << "Zero" << endl;
    }
    else if (b < 0 && (b - a) % 2 == 0){
        cout << "Negative" << endl;
    }
    else{
        cout << "Positive" << endl;
    }
}
