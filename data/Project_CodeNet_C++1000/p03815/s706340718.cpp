#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll X;
    cin >> X;
    if (X % 11 == 0){
        cout << (X / 11) * 2 << endl;
    }
    else if (X % 11 <= 6){
        cout << (X / 11) * 2 + 1 << endl;
    }
    else{
        cout << (X / 11) * 2 + 2 << endl;
    }
}

