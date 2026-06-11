
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string n;
    cin>>n;
    bool f=0;
    long long s=0 , a ;
    for (int i=0 ; i<n.size() ; ++i)
    {
        if (n[i]=='A'&&f==0)
        {
            f=1;
        }
        if (f==1)
        {
            s+=1;
            if (n[i]=='Z')
            {
                a=s;
            }
        }
    }
    cout<<a<<endl;
}
