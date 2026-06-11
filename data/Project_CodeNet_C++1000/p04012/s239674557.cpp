#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    int cot[27]= {0},flag=0;
    set<char>s;
    cin>>str;
    flag=0;
    sort(str.begin(),str.end());
    for(int i=0; i<str.size(); i++)
    {
        cot[str[i]-97]++;

    }
    for(int i=0; i<26; i++)
    {
        if(cot[i]%2==1)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;
}
