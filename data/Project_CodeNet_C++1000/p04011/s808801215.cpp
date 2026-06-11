// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    
    int N,K,X,Y;
    // 入力
    cin >> N >> K >> X >> Y;
    
    if (N < K) K = N;
        
    int answer = K*X+(N-K)*Y;
    
    //　出力
    cout << answer << endl;
}

// GCC reference:
//   https://gcc.gnu.org/

// C++ language references:
//   https://cppreference.com/
//   https://isocpp.org/
//   http://www.open-std.org/jtc1/sc22/wg21/

// Boost libraries references:
//   https://www.boost.org/doc/
