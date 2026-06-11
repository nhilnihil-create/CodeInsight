#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <cmath>
#include <queue>
#include <map>
using namespace std;

int64_t mod = 998244353 ;

vector<int> getprime(int n){
    vector<int> p(0) ;
    vector<bool> table(n+1,0) ;
    for (int i = 2; i <= n; i++)
    {
        if (table.at(i) == 0)
        {
            p.push_back(i) ;
            for (size_t j = 2; j < n/i ; j++)
            {
                table.at(i*j) = 1 ;
            }
            
        }
        
    }
    return p ;
}

int d(int64_t n){
    int re = 1 ;
    while (1)
    {
        n /= 10 ;
        if (n > 0)
        {
            re ++ ;
        }else
        {
            return re ;
        }
        
        
    }
    
}

int main(){
    int n,m ;
    cin >> n >> m ;
    vector<bool> path(n,0) ;
    path.at(0) = 1 ;
    vector<int> ball(n,1) ;
    int x,y ;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y ;
        if (path.at(x-1))
        {
            path.at(y-1) = 1 ;
        }
        ball.at(x-1) -- ;
        ball.at(y-1) ++ ;
        if (ball.at(x-1) == 0)
        {
            path.at(x-1) = 0 ;
        }
        
    }
    int ans = 0 ;
    for (int i = 0; i < n; i++)
    {
        ans += path.at(i) ;
    }
    cout << ans << endl ;
}