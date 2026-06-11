#include<bits/stdc++.h>
using namespace std;
string m,n="CODEFESTIVAL2016";
int tot; 
int main()
{
    cin>>m;
    for(int i=0;i<16;i++)
	{
        if(m[i]!=n[i]) tot++;
    }
    cout<<tot;
	cout<<endl;
    return 0;
}