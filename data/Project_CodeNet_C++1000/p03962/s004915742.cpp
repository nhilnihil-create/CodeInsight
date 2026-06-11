//
//  A - AtCoDeerくんとペンキ.cpp
//  Practice
//
//  Created by Hajime Sakamoto on 2020/05/29.
//  Copyright © 2020 Hajime Sakamoto. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>

using namespace std;


int main(){
    
    int a, b, c;
    
    cin >> a >> b >> c;
    
    if (a!=b & a!=c & b!=c){
        cout << 3;
    }
    else if (a==b & a==c){
        cout << 1;
    }
    else {
        cout << 2;
    }
    
    return 0;
    
}
