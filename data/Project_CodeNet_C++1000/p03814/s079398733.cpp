#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int N = s.size();
    int start, end;
    for (int i = 0; i < N; ++i)
    {
        if (s[i] == 'A')
        {
            start = i;
            break;
        }
    }
    for (int i = 0; i < N; ++i)
    {
        if (s[N - 1 - i] == 'Z')
        {
            end = N - 1 - i;
            break;
        }
    }
    cout << end - start + 1 << endl;
}
