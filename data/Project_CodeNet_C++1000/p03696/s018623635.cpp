#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    string S;
    cin >> N;
    cin >> S;
    int a = 0;
    int b = 0;
    int cnta = 0;

    for (char c : S)
    {
        if ('(' == c)
        {
            cnta += 1;
        }else
        {
            if (cnta > 0)
            {
                cnta -= 1;
            }else
            {
                a += 1;
            }
            
        }
        
    }

    b = cnta;

    for (int i = 0; i < a; i++)
    {
        cout << '(';
    }
    
    cout << S;

    for (int i = 0; i < b; i++)
    {
        cout << ')';
    }
    
    cout << endl;

    return 0;
}
