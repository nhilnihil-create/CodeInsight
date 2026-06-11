
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n , t=0 , mx ;
    cin>>n;
    string s;
    cin>>s;
    mx=t;
    for (int i=0 ; i<n ; ++i)
    {
        if (s[i]=='I')
        {
            t+=1;
            if (t>mx)
            {
                mx=t;
            }
        }
        else
        {
            t-=1;
        }
    }
    cout<<mx<<endl;
}
