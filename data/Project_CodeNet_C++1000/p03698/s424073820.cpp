#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    int a[26] = {0};

    for(int i=0; i<S.size(); i++) a[S[i]-'a'] += 1;
    for(int i=0; i<26; i++)
    {
        if(2 <= a[i])
        {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    return 0;
}