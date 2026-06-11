#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    long long N, A, B;
    string S;
    long long pass = 0;
    long long for_pass = 0;
    cin >> N >> A >> B;
    cin >> S;

    for (int i = 0; i < N; i++)
    {
        if (S[i] == 'a')
        {
            if (pass < A + B)
            {
                puts("Yes");
                pass++;
            }
            else
                puts("No");
        }
        else if (S[i] == 'b')
        {
            if (pass < A + B && for_pass < B)
            {
                puts("Yes");
                for_pass++;
                pass++;
            }
            else
                puts("No");
        }
        else
        {
            puts("No");
        }
    }
}