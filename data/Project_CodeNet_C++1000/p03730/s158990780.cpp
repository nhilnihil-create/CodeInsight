#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int sum = a + b +c;

    rep(i,1000000){
        int sum = a * i + b + c;
        if (a * i % a == 0 &&  a * i % b == c){
            
            cout << "YES" << endl;
            return 0 ;
        }
    }
    cout << "NO" << endl;
    return 0;
}