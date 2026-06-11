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
    int A,B,C,D,i,p,s,g;
    cin >> A >> B >> C >> D;
    if(A < C){
        s = C;
    }
    else{
        s = A;
    }
    if (B < D)
    {
        g = B;
    }
    else
    {
        g = D;
    }
    if(g - s > 0){
        cout << g - s << endl;
    }
    else{
        cout << 0 << endl;
    }
}