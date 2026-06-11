#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include <sstream>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include <iomanip>
#include <regex>
#include <initializer_list>
#include <deque> 
#define DBL_MIN 0.000000000000001

#include <iostream>
using namespace std;


int main(void){
    long x,y;
    cin >> x >> y;
    int ax = abs(x);
    int ay = abs(y);
    int diff = max(ax,ay) - min(ax,ay);
    if(y == 0){
        if(x < 0){
            cout << abs(x) << endl;
        }else{
            cout << abs(x) + 1 << endl; 
        }
    }else if(0 <= x && 0 <= y){
        if(y >= x){
            cout << y - x << endl;
        }else{
            cout <<  x - y + 2 << endl;
        }
    }else if(x < 0 && y < 0){
        if(y >= x){
            cout << y - x << endl;
        }else{
            cout << abs(y) - abs(x) + 2 << endl;
        }
    } else if(x < 0 && 0 <= y){
        if(abs(y) >= abs(x)){
            cout << abs(y) - abs(x) + 1 << endl;
        }else{
            cout << abs(x) - abs(y) + 1  << endl;
        }
    }else if(0 <= x && y < 0){
        if(abs(x) > abs(y)){
            cout << abs(x) - abs(y) + 1 << endl;
        }else{
            cout << abs(y) - x + 1 << endl;
        }
    }
}

