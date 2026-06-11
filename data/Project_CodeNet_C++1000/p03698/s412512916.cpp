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
    cin >> s ;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i+1; j < s.size(); j++)
        {
            if (s.at(i) == s.at(j))
            {
                cout << "no" << endl ;
                return 0 ;
            }
            
        }
        
    }
    cout << "yes" << endl ;
}
