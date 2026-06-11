#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int x = b-a, y = c-b;

    if(x == y){
        cout << "YES" << endl;
    }

    else{
        cout << "NO" << endl;
    }
   
}
