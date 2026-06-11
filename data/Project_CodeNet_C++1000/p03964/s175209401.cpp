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
//#define MAX 100100
//#define NIL -1

int main() {
    LL n;
    cin >> n;
    vector<LL> t(n);
    vector<LL> a(n);
    for(LL i=0; i<n; i++){
        cin >> t[i] >> a[i];
    }

    LL ans_t=t[0];
    LL ans_a=a[0];
    LL tmp_t;
    LL tmp_a;
    for(LL i=1; i<n; i++){
        if(ans_t%t[i]==0){
            tmp_t=ans_t/t[i];
        }else{
            tmp_t=ans_t/t[i]+1;
        }
        if(ans_a%a[i]==0){
            tmp_a=ans_a/a[i];
        }else{
            tmp_a=ans_a/a[i]+1;
        }
        ans_t=max(tmp_t,tmp_a)*t[i];
        ans_a=max(tmp_t,tmp_a)*a[i];
    }

    cout << ans_t+ans_a << endl;

    return 0;
}
