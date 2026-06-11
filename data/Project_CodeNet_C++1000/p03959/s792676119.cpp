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

int64_t mod = 1000000007 ;

int main(){
    int n ;
    cin >> n ;
    vector<int> t(n) ;
    vector<int> a(n+1) ;
    a.at(n) = 0 ;
    for (int i = 0; i < n; i++)
    {
        cin >> t.at(i) ;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a.at(i) ;
    }
    vector<pair<bool,int> > h(n,pair<bool,int>(make_pair(0,0))) ;
    int64_t ans = 1 ;
    h.at(0).first = 1 ;
    h.at(0).second = t.at(0) ;
    for (int i = 1; i < n; i++)
    {
        if (t.at(i) > t.at(i-1))
        {
            h.at(i).first = 1 ;
            h.at(i).second = t.at(i) ;
        }else
        {
            h.at(i).second = t.at(i) ;
        }
        
        
    }
    for (int i = 0; i < n; i++)
    {
        if (a.at(n-1-i) > a.at(n-i))
        {
            if (h.at(n-1-i).first == 1)
            {
                if (h.at(n-1-i).second != a.at(n-1-i))
                {
                    ans = 0 ;
                    break ;
                }
                
            }else
            {
                h.at(n-1-i).first = 1 ;
                h.at(n-1-i).second = a.at(n-1-i) ;
            }
            
            
            
        }else
        {
            if (h.at(n-1-i).first == 1)
            {
                if (h.at(n-1-i).second > a.at(n-1-i))
                {
                    ans = 0 ;
                    break ;
                }
                
            }else
            {
                h.at(n-1-i).second = min(h.at(n-1-i).second, a.at(n-1-i)) ;
            }
            
            
        }
        
    }
    if (ans != 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (h.at(i).first == 0)
            {
                ans *=  h.at(i).second ;
            }
            
            if (ans > mod)
            {
                ans %= mod ;
            }
            
        }
        
    }
    
    
    cout << ans << endl ;
}
