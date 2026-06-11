#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    string s, t;
    cin >> s >> t;

    bool same;
    for (int i = 0; i < N; i++)
    {
        same = true;
        for (int j = 0; j < N - i; j++)
        {
            if (s[i + j] != t[j]) same = false;
        }
        if (same)
        {
            cout << 2 * N - (N - i) << endl;
            return 0;
        }
        
    }
    
    cout << 2 * N << endl;

    return 0;
}