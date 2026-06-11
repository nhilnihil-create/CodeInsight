#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <numeric>
#include <queue>
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

int64_t solve(vector<int> a,bool next){
    bool nextposi = next ;
    int64_t ans = 0 ;
    int64_t sum = 0 ;
    for (int i = 0; i < a.size(); i++)
    {
        sum += a.at(i) ;
        if (nextposi != (sum > 0))
        {
            if (nextposi == 1)
            {
                ans += abs(sum - 1) ;
                sum = 1 ;
            }else
            {
                ans += abs(sum + 1) ;
                sum = -1 ;
            }
            
            
        }
        
        nextposi = !nextposi ;
    }
    return ans ;
    
}

int main(){
    int n ;
    cin >> n ;
    vector<int> a(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> a.at(i) ;
    }
    int64_t ans = 0 ;
    if (a.at(0) == 0)
    {
        a.at(0) = 1 ;
        ans = min(solve(a,0),solve(a,1)) ;
        a.at(0) = -1 ;
        int64_t ansp = min(solve(a,0),solve(a,1)) ;
        ans = min(ans,ansp) + 1;
    }else
    {
        ans = min( solve(a,0), solve(a,1) ) ;
    }
    
    cout << ans << endl ;
}
