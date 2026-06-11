#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <cmath>
#include <stack>
#include <map>
using namespace std;



int main(){
    int n ;
    cin >> n ;
    vector<int64_t> a(n) ;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a.at(i) ;
    }
    int64_t ans = 0 ;
    ans += a.at(0) / 2 ;
    a.at(0) %= 2 ;
    for (size_t i = 0; i < n-1; i++)
    {
        if (a.at(i) == 1 && a.at(i+1) > 0)
        {
            ans ++ ;
            a.at(i) -= 1 ;
            a.at(i+1) -= 1 ;
        }
        ans += a.at(i+1) /2 ;
        a.at(i+1) %= 2 ;
        
    }
    cout << ans << endl ;
}