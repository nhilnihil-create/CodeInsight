#include <iostream>
#include <vector>
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
    LL n;
    LL a;
    LL b;
    LL ans=0;
    LL num=0;
    cin >> n >> a >> b;
    vector<LL> x(n);

    for(LL i=0; i<n; i++){
        cin >> x[i];
    }

    for(LL i=1; i<n; i++){
        LL tmp=(x[i]-x[i-1])*a;
        if(tmp<b){
            ans+=tmp;
            num++;
        }
    }

    ans+=(n-1-num)*b;

    cout << ans << endl;

    return 0;
}
