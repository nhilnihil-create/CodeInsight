#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
int main()
{
    int x,a,b;
    cin >> x >> a >>b;
    if(a >= b){
        cout << "delicious" << endl;
    }
    else if (a+x >= b){
        cout << "safe" << endl;
    }else{
        cout << "dangerous" << endl;
    }
}