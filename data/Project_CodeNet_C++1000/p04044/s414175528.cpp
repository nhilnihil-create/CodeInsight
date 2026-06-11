// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n, l;
    vector<string> S;
    cin >> n >> l ;
    for( int i = 0 ; i < n ; i++){
        string str;
        cin >> str;
        S.push_back(str);
    }
    
    sort(S.begin(), S.end());
    
    for_each(S.begin(), S.end(), [](const string& str){
        cout << str;
    });
    return 0;
}

// GCC reference:
//   https://gcc.gnu.org/

// C++ language references:
//   https://cppreference.com/
//   https://isocpp.org/
//   http://www.open-std.org/jtc1/sc22/wg21/

// Boost libraries references:
//   https://www.boost.org/doc/
