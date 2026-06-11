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

int main(){
    int n ;
    string s ;
    cin >> n >> s ;
    int ans = 0 ;
    int now = 0 ;
    for (int i = 0; i < s.size(); i++)
    {
        if (s.at(i) == 'I')
        {
            now ++ ;
        }else
        {
            now -- ;
        }
        ans = max(now,ans) ;
        
    }
    cout << ans << endl ;
}
