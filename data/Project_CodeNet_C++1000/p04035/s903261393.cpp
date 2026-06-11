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
    int n,l ;
    cin >> n >> l ;
    int a ;
    int back ;
    cin >> back ;
    for (int i = 0; i < n-1; i++)
    {
        cin >> a ;
        if (back + a >= l)
        {
            cout << "Possible" << endl ;
            for (int j = 1; j < i+1 ; j++)
            {
                cout << j << endl ;
            }
            for (int j = 0; j < n-1-i; j++)
            {
                cout << n-1-j << endl ;
            }
            return 0 ;
            
        }else
        {
            back = a ;
        }
        
        
    }
    
    cout << "Impossible" << endl ;
    
    
    
}