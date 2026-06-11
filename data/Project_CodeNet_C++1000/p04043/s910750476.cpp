#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,f=0,s=0,i;


    for(i=0;i<3;i++)
    {
        cin >> n;
        if(n==5)
            f++;
        else if(n==7)
            s++;
    }

if(f==2 && s==1)
    cout << "YES";
else
cout << "NO";

}
