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
    ll a,b;
    string x;
    cin >> a >> b;
    for (int i=0;i<a;++i){
        for (int j=0;j<b;++j){
            cin >> x;
            if (x=="snuke"){
                cout << (char)('A'+j) << i+1 << endl;
                break;
            }
        }
    }
    return 0;
}
