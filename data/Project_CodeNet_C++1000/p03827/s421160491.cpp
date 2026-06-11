#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    int max=0;
    int chk=0;
    for(int i=0; i<S.size(); i++)
    {
        if(S.at(i)=='I')
        {
            chk++;
        }
        else
        {
            chk--;
        }
        if(chk>max)
        {
            max=chk;
        }
    }
    cout << max << endl;
}