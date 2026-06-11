#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,A,B,a=0,b=0;
    cin>>n>>A>>B;
    string s;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='a')
        {
            if(a+b<A+B)
                {
                    cout<<"Yes\n";
                    ++a;
                }
            else
                cout<<"No\n";

        }
        else if(s[i]=='b')
        {
            if(a+b<A+B&&b<B)
                {
                    cout<<"Yes\n";
                    ++b;
                }
            else
                cout<<"No\n";
        }
        else
            cout<<"No\n";
    }


    return 0;
}

