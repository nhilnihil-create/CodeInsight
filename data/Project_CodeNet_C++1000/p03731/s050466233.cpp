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
#define NIL -1

int main() {
    int n;
    LL t;
    LL ans=0;
    cin >> n >> t;
    vector<LL> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    for(int i=1; i<n; i++){
        if(a[i]-a[i-1]>=t){
            ans+=t;
        }else{
            ans+=a[i]-a[i-1];
        }
    }
    ans+=t;

    cout << ans << endl;

    return 0;
}