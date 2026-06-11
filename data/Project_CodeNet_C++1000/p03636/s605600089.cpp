#include <bits/stdc++.h>
#include <string>
using namespace std;
int main(void){
    // Your code here!
    
    string s;
    cin >> s;
    
    int sie = s.size() - 2;
    string size = to_string(sie); 
    
    cout << s.replace ( 1, sie, size ) << endl;
    

}
