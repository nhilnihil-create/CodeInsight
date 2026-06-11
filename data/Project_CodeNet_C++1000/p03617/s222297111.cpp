#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <sstream>
#include <numeric>
#include <queue>
#include <sstream>
#include <set>
using namespace std;

int64_t min(int64_t a,int64_t b) {
    if (a > b)
    {
        return b ;
    }else
    {
        return a ;
    }
}


int main(){
    int64_t q,h,s,d ;
    int64_t n ;
    cin >> q >> h >> s >> d ;
    cin >> n ;
    q *= 4 ;
    h *= 2 ;
    int64_t buy = min(min(q,h),s) ;
    int64_t ans = 0 ;
    if (2*buy < d)
    {
        ans = buy*n ;
    }else
    {
        ans += d * (n/2) ;
        ans += buy * (n%2) ;
    }
    
    cout << ans << endl ;
}
