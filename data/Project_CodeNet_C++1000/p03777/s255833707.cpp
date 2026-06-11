#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
#include<map>
using namespace std;


int main() {
    char a, b;
    cin >> a >> b;
    if(a == 'H'){
        if(b == 'D'){
            cout << 'D';
        }
        else{
            cout << 'H';
        }
    }
    else{
        if(b == 'H'){
            cout << 'D';
        }
        else{
            cout << 'H';
        }
    }
    cout << endl;
}
