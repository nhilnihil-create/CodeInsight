#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
 
    string a;
    cin >> a;
    
    unsigned long b;
    b = a.size()-1;
    
    cout << a[0] << a.size()-2 << a[b];
    
    
    

    return 0;
    
}
