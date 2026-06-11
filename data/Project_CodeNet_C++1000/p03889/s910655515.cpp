#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin >> str;
    for(int i = str.length() - 1, j = 0; i >= 0; i--, j++)
    {
        if(!(str[i] == 'p' && str[j] == 'q' || str[i] == 'q' && str[j] == 'p' || str[i] == 'd' && str[j] == 'b' || str[i] == 'b' && str[j] == 'd'))
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}