#include <bits/stdc++.h>


using namespace std;
using ll= long long;
using pii = pair<int, int>;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;


int main (){
    char a,b;
    cin >>a >> b;
    if (a == 'H'){
        cout << b << endl;
    }
    else {
        cout << (b == 'H'? 'D' : 'H') << endl;
    }
    
    return 0;
}