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
    string s ;
    cin >> s ;
    bool N = 0 ;
    bool S = 0 ;
    bool W = 0 ;
    bool E = 0 ;
    for (int i = 0; i < s.size(); i++)
    {
        if (s.at(i) == 'N')
        {
            N = 1 ;
        }else if (s.at(i) == 'S')
        {
            S = 1 ;
        }else if (s.at(i) == 'W')
        {
            W = 1 ;
        }else if (s.at(i) == 'E')
        {
            E = 1 ;
        }
        
    }
    if (!(N^S)&!(W^E))
    {
        cout << "Yes" ;
    }else
    {
        cout << "No" ;
    }
    cout << endl ;
    
    
}