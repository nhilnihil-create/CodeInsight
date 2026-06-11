#include <iostream>
//#include <vector>
//#include <cstdlib>
//#include <algorithm>
//#include <cmath>
using namespace std;
 
int main() {
    string s;
    
    cin >> s;
    
    //cout << s.size();
   for(int i=0; i<s.size(); i = i + 2){
        cout << s.at(i);       
    }
    
    return 0;
}