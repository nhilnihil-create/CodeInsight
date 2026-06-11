#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, a, b;
    string str;
    cin >> n >> a >> b >> str;
    int cnt = a + b;
    for (int i = 0; i < n; ++i)
    {
        if (str[i] == 'a' && cnt > 0)
        {
            cout << "Yes" << endl;
            --cnt;
        }
        else if (str[i] == 'b' && cnt > 0 && b > 0)
        {
            cout << "Yes" << endl;
            --cnt;
            --b;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}