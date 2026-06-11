#include <bits/stdc++.h>
using namespace std;

string S;
int sums,sumt;

int main()
{
    cin>>S;
    for(int i=0;i<S.size();i++)
    {
        if(S[i] == 'S') sums++;
        if((sums)&&(S[i]=='T'))
        {
            sums--;
            sumt+=2;
        }
    }
    cout<<S.size()-sumt<<"\n";
}