#include<bits/stdc++.h>
#include<string>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
int main()
{
    fastio;
    string str,a;
    cin>>str;
    int i,n= str.length();
    for (i=0;i<n;i++)
    {
        if (i%2==0)
            a.push_back(str[i]);
    }
    cout<<a<<endl;
}