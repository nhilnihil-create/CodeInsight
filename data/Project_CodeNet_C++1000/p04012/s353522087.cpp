#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[105];
    cin>>a;
    int s=1;
    int l=strlen(a);
    sort(a,a+l);
    for(int i=0;i<strlen(a)-1;++i)
    {
        if(a[i]==a[i+1])
            ++s;
        else
        {
            if(s%2==1)
            {
                cout<<"No"<<endl;
                return 0;
            }
            s=1;

        }
    }
    if(s%2==1)
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;
    return 0;
}
