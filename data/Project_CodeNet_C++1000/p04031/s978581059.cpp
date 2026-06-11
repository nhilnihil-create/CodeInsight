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
    cin >> n;
    vector<LL> a(n);
    for(LL i=0; i<n; i++){
        cin >> a[i];
    }

    LL x=0;
    LL ans;
    LL min_ans=-1;
    for(LL i=0; i<n; i++){
        x+=a[i];
    }
    x/=n;
    x--;
    for(LL i=x; i<x+3; i++){
        ans=0;
        for(LL j=0; j<n; j++){
            ans=ans+(a[j]-i)*(a[j]-i);
        }
        if(min_ans==-1 || min_ans>ans){
            min_ans=ans;
        }
    }

    cout << min_ans << endl;


    return 0;
}
