#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <string>
#include <stdlib.h>
using namespace std;
//cout <<  << endl;
typedef long long int ll;
typedef long double ld;

int main(){
    string x;
    cin >> x;
    for(int i=0;i<4;++i){
        cout << x[i];
    }
    cout << " ";
    for (int i=4;i<12;++i){
        cout << x[i];
    }
    cout << endl;
    return 0;
}
