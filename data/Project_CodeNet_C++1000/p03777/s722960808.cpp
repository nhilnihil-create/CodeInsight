#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
//const int INF = 1<<29;
//const int MODINF = 1000000007;
using namespace std;

int main(){
    char a, b;
    cin >> a >> b;
    if (b == 'H'){
        if (a == 'H') cout << "H" << endl;
        else cout << "D" << endl;
    }
    else{
        if (a == 'H') cout << "D" << endl;
        else cout << "H" << endl;
    }
}