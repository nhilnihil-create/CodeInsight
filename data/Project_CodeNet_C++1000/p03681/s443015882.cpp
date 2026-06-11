#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
#include <math.h>
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
 
#define MOD 1000000007
//#define MAX 100100
//#define NIL -1

int main(){
    LL n;
    LL m;
    LL ans=1;

    cin >> n >> m;
    if(abs(n-m)>=2){
        ans=0;
    }else{
        for(LL i=1; i<=n; i++){
            ans=(ans*i)%MOD;
        }
        for(LL i=1; i<=m; i++){
            ans=(ans*i)%MOD;
        }
        if(n==m){
            ans=(ans*2)%MOD;
        }
    }

    cout << ans << endl;

    return 0;
}
