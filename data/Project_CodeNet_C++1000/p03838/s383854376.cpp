#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <bitset>
#include <queue>
#include <utility>
#include <functional>
#include <sstream>
using namespace std;
#define ll long long
 
int main(void){
    ll x, y;
    cin >> x >> y;
    if(abs(y)>=abs(x)){
        if(x>=0 && y >= 0) cout << y-x << endl;
        else if(x>=0 && y<0) cout << (-1*y)-x+1 << endl;
        else if(x<0 && y>=0) cout << abs(y-(-1)*x)+1 << endl;
        else cout << abs(y-x)+2 << endl;  
    }
    else if(abs(y)<abs(x)){
        if(x>=0 && y > 0) cout << x-y+2 << endl;
        else if(x>0 && y<=0) cout << y-(-1)*x+1 << endl;
        else if(x<0 && y>0) cout << abs(y-(-1)*x)+1 << endl;
        else cout << abs(y-x) << endl;  
    }
    return 0;
}