#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

#define rep(i, n)   for(int i=0; i<(n); i++)

int main(void)
{
    int N, A, B;
    std::cin >> N >> A >> B;
    std::string S;
    std::cin >> S;

    int all = 0;
    int foregin = 0;
    rep(i, N)
    {
        bool isOk = false;

        if( S[i] == 'a')
        {
            if( all < A + B )
            {
                isOk = true;
                all++;
            }
        }
        else if( S[i] == 'b' )
        {
            if( all < A+B )
            {
                if( foregin < B )
                {
                    isOk = true;
                    all++;
                    foregin++;
                }
            }
        }

        if( isOk == true )
        {
            std::cout << "Yes" << std::endl;
        }
        else
        {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}