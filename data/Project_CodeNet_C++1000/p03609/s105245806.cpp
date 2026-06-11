#include <bits/stdc++.h>
using namespace std;

int main(){

    int X, t, res;

    cin >> X >> t;

    res = X - t;

    if(res < 0){
        res = 0;
    }

    cout << res << endl;

}
