#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{
    int a,b,c;
    cin >> a >> b >> c;

    rep(i,b){
        if(i*a%b == c){
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    
    return 0;
}