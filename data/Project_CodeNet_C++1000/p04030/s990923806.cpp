#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    string  s;
    int     size;
    
    cin >> s;
    
    size = s.size();
    
    for ( int ii = 0; ii < size; ii++ ) {
        if ( s[ii] == 'B' ) {
            if ( ii == 0 ) {
                s.erase(ii, 1);
                ii--;
            } else {
                s.erase(ii - 1, 2);
                ii -= 2;
            }
            size = s.size();
        }
    }
    
    cout << s << endl;
    
    return 0;
    
}