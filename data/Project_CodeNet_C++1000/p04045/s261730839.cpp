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
#define MAX 100100
//#define NIL -1

int main() {
    LL n;
    LL k;
    cin >> n >> k;
    vector<LL> num_list(k);
    for(LL i=0; i<k; i++){
        cin >> num_list[i];
    }

    LL ans;

    for(LL i=n; i<100000; i++){
        bool is_ok=true;
        LL kiyu=i;
        LL kbt;
        //cout << i << endl;
        while(kiyu>0){
            kbt=kiyu%10;
            for(LL j=0; j<k; j++){
                if(kbt==num_list[j]){
                    is_ok=false;
                    break;
                }
            }
            kiyu/=10;
            //cout << kiyu << endl;
        }
        if(is_ok==true){
            ans=i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
