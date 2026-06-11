#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
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
//#define MAX 10000100
//#define NIL -1

int main() {
    LL a;
    LL b;
    LL x;
    LL ans;
    cin >> a >> b >> x;
    if(a==0){
        ans=b/x+1;
    }else{
        ans=b/x-(a-1)/x;
    }

    cout << ans << endl;

    return 0;
}
