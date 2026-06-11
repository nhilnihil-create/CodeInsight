#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int x, y;
    cin >> x >> y;
    if(x == 2 || y == 2){
        cout << "No" << endl;
    }else if(x == 4 || x == 6 || x == 9 || x == 11){
        if(y == 4 || y == 6 || y == 9 || y == 11){
            cout << "Yes" << endl;
        }else {
            cout << "No" << endl;
        }
    }else{
        if(y == 4 || y == 6 || y == 9 || y == 11){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }
}