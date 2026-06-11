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
 
#define MOD 1000000007
#define MAX 100100
//#define NIL -1

int main() {
    LL n;
    LL tmp_a;
    bool is_ok=true;
    LL ans=1;
    vector<LL> num_list(MAX, 0);
    cin >> n;
    for(LL i=0; i<n; i++){
        cin >> tmp_a;
        num_list[tmp_a]++;
    }

    LL start=(n-1)%2;
    for(LL i=start; i<n; i=i+2){
        if(i==0 && num_list[i]!=1){
            //cout << i << " test" << endl;
            is_ok=false;
        }else if(i!=0 && num_list[i]!=2){
            //cout << i << " test2" << endl;
            is_ok=false;
        }
    }

    if(is_ok==false){
        cout << 0 << endl;
    }else{
        for(LL i=start; i<n; i=i+2){
            ans=ans*num_list[i];
            ans=ans%MOD;
        }
        cout << ans << endl;
    }

    return 0;
}
