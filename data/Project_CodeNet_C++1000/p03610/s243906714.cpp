#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    string S;
    cin>> S;
    string ans;
    for (int i = 0; i < S.size(); i++)
    {
        if (i%2==0)

        {
           ans+=S.at(i);
        }
    }
    cout << ans <<endl;
    return 0;
}
