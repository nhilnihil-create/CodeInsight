#include <iostream>
//#include <vector>
//#include <string>
#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 100100
//#define NIL -1
//#define INFTY 1000000000000000000

int main(){
    LL w;
    LL h;
    LL n;
    cin >> w >> h >> n;
    LL x;
    LL y;
    LL a;

    LL max_x=w;
    LL min_x=0;
    LL max_y=h;
    LL min_y=0;

    for(LL i=0; i<n; i++){
        cin >> x >> y >> a;
        if(a==1){
            min_x=max(min_x,x);
        }else if(a==2){
            max_x=min(max_x,x);
        }else if(a==3){
            min_y=max(min_y,y);
        }else{
            max_y=min(max_y,y);
        }
    }

    if(min_x>=max_x || min_y>=max_y){
        cout << 0 << endl;
    }else{
        cout << (max_x-min_x)*(max_y-min_y) << endl;
    }

    return 0;
}
