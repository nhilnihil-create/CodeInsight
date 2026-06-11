#include <iostream>
#include <string>
//#include <vector>
//#include <cstdlib>
//#include <algorithm>
//#include <cmath>
using namespace std;
 
int main() {
    string s;
    int count_A=0;
    int count_Z=0;    
    cin >> s;
    
  //cout << s << "s.size=" << s.size() << endl;
   for(int i=0; i<s.size(); i++){
        if(s[i] == 'A'){
             count_A=i;
             break;
        }
    }
    
    for(int i=s.size(); i>0; i--){
        if(s[i] == 'Z'){
             count_Z=i;
             break;  
        }
    }
    
    //cout << "count_A=" << count_A << endl;
    //cout << "count_Z=" << count_Z << endl;
    cout << count_Z - count_A + 1 << endl;

    return 0;
}