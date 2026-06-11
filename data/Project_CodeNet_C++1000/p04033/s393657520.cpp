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
    int a,b ;
    cin >> a >> b ;
    if (a < 1 && b > -1)
    {
        cout << "Zero" << endl ;
    }else if (a > 0)
    {
        cout << "Positive" << endl ;
    }else if ((b - a) % 2 == 1)
    {
        cout << "Positive" << endl ;
    }else
    {
        cout << "Negative" << endl ;
    }
    
    
    
    
}