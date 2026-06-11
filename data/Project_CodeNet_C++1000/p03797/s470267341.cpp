#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int s , c;
    cin >> s>> c;
    c/=2;
    long long int a ;
    if (s >= c){
        cout << c;
    }
    else{
        a = c-s;
        cout << s+(a/2);
    }
}
