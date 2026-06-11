#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 1000000007;


int main()
{
    int a, b;
    cin >> a >> b;
    if(a == b){
        cout << "Draw" << endl;
    }else if((a > b || a == 1) && b != 1){
        cout << "Alice" << endl;
    }else{
        cout << "Bob" << endl;
    }
}