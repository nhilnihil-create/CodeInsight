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
    string x,y="CODEFESTIVAL2016";
    ll z=0;
    cin >> x;
    for (ll i=0;i<x.size();++i){
        if (x[i]!=y[i]){
            ++z;
        }
    }
    cout << z << endl;
    return 0;
}
