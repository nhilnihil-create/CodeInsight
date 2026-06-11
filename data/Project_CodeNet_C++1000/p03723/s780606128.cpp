#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <cmath>
#include <stack>
#include <map>
#include <iomanip>
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
    int a,b,c ;
    cin >> a >> b >> c ;
    int na,nb,nc ;
    int ans = 0 ;
    while (1)
    {
        if (a%2 != 0 || b%2 != 0 || c%2 != 0)
        {
            cout << ans << endl ;
            return 0 ;
        }
        na = b/2 + c/2 ;
        nb = c/2 + a/2 ;
        nc = a/2 + b/2 ;
        if (a == na && b == nb && c == nc )
        {
            cout << -1 << endl ;
            return 0 ;
        }else
        {
            ans ++ ;
            a = na ;
            b = nb ;
            c = nc ;
        }
        
        
    }
        
}