#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <algorithm>
#include <set>
#include <map>
#include <stdlib.h>
using namespace std;
int main(){
    long int A,B,C,p,i;
    p = 0;
    cin >> A >> B >> C;
    for(i = A;i <= A * B + 2;i += A){
        if(i % B == C){
            cout << "YES" << endl;
            p = 1;
            break;
        }
    }
    if(p != 1){
        cout << "NO" << endl;
    }
}