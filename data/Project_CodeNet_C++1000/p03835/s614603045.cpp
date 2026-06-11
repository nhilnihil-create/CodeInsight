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
//#define MAX 100100
//#define NIL -1

int main() {
    LL k;
    LL s;
    LL ans=0;
    cin >> k >> s;
    for(LL i=0; i<=k; i++){
        for(LL j=0; j<=k; j++){
            LL l=s-i-j;
            if(l>=0 && l<=k){
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}