#include <iostream>
#include <vector>
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

int main() {
    LL n;
    cin >> n;
    vector<LL> a(n);
    LL sum_m=0;
    LL sum_p=0;
    LL ans_m=0;
    LL ans_p=0;
    LL ans;
    for(LL i=0; i<n; i++){
        cin >> a[i];
    }

    for(LL i=0; i<n; i++){
        sum_m+=a[i];
        if(i%2==0){
            if(sum_m>=0){
                ans_m=ans_m+1+sum_m;
                sum_m=-1;
            }
        }else{
            if(sum_m<=0){
                ans_m=ans_m+1-sum_m;
                sum_m=1;
            }
        }
        //cout << ans_m << " " << sum_m << endl;
    }

    //cout << "test" << endl;

    for(LL i=0; i<n; i++){
        sum_p+=a[i];
        if(i%2==0){
            if(sum_p<=0){
                ans_p=ans_p+1-sum_p;
                sum_p=1;
            }
        }else{
            if(sum_p>=0){
                ans_p=ans_p+1+sum_p;
                sum_p=-1;
            }
        }
        //cout << ans_p << " " << sum_p << endl;
    }

    ans=min(ans_p, ans_m);

    cout << ans << endl;

    return 0;
}
