#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <cmath>
#include <stack>
#include <map>
using namespace std;

int64_t gcd(int64_t a,int64_t b){
    if(a < b)
    {
        int64_t temp = a;
        a = b ;
        b = temp;
    }
    int64_t copya = a;
    int64_t copyb = b;
    int64_t r = a%b ;
    while (r != 0)
    {
        a = b ;
        b = r ;
        r = a%b ;
    }
    return b ;
    
}


int main(){
    int n,k ;
    cin >> n >> k ;
    int m = 0;
    int G = 0 ;
    int num ;
    for (size_t i = 0; i < n; i++)
    {
        cin >> num ;
        if (i == 0)
        {
            m = num ;
            G = num ;
        }else
        {
            m = max(m,num) ;
            if (G != 1)
            {
                G = gcd(G,num) ;
            }
            
        }
        
        
    }
    if (k <= m && k%G == m%G)
    {
        cout << "POSSIBLE" ;
    }else
    {
        cout << "IMPOSSIBLE" ;
    }
    cout << endl ;
    
}