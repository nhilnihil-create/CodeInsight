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
#define MAX 100100
//#define NIL -1

int main() {
    LL n;
    LL ans=0;
    cin >> n;
    ans=ans+(n/11)*2;
    n=n%11;
    if(n>0){
        if(n<=6){
            ans++;
        }else{
            ans+=2;
        }
    }

    cout << ans << endl;

    return 0;
}