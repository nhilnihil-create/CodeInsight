#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string S;
    cin >> S;
    int ans = 0;
    for (string::iterator itr = S.begin() + 1; itr != S.end(); itr++)
    {
        if (*itr != *(itr - 1)) ans++;
    }

    cout << ans << endl;
    
    return 0;
}