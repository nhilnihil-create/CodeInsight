#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <deque>
using namespace std;

int main() {
    //input
    long x , y; cin >> x >> y;
    long cal = 0;
    long xm, ym;
    xm = -1 * x;
    ym = -1 * y;


    //compute
    if(x <= y){
        cal = min(abs(y - x),abs(y - xm)+ 1);
        cal = min(cal,abs(ym - x)+ 1);
        cal = min(cal,abs(ym - xm)+ 2);
    }else{
        cal = min(abs(y - xm)+ 1,abs(ym - x)+ 1);
        cal = min(cal,abs(ym - xm)+ 2);        
    }

    //output
    cout << cal << endl;
}