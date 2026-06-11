//
//  A - キャンディーと2人の子供.cpp
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
    int candy_sum;
    
    cin >> a >> b >> c;
    
    if (a==b & a==c){
        cout << "No";
    }
    else if (a>b & a>c){
        candy_sum = b+c;
        if (a == candy_sum){
            cout << "Yes";
        }
        else cout << "No";
    }
    else if (b > c){
        candy_sum = a+c;
        if (b == candy_sum){
            cout << "Yes";
        }
        else cout << "No";
    }
    else{
        candy_sum = a+b;
        if (c == candy_sum){
            cout << "Yes";
        }
        else cout << "No";
    }
    
}
