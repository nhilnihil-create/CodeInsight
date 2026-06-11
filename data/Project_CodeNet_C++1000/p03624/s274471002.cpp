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
    string s ;
    cin >> s ;
    vector<bool> c(26,0) ;
    for (int i = 0; i < s.size(); i++)
    {
        int num = s.at(i) - 'a' ;
        c.at(num) = 1 ;
    }
    for (int i = 0; i < 26; i++)
    {
        if (c.at(i) == 0)
        {
            char ans = 'a' + i ;
            cout << ans << endl ;
            return 0 ;
        }
        
    }
    

    cout << "None" << endl;
    
    
}
