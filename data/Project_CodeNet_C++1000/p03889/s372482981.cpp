#include<bits/stdc++.h>
using namespace std;
string st1,st2;
int main()
{
    cin>>st1;
    int m=-1;
    for (int i=st1.size()-1;i>=0;i--) 
    {
    	m++;
        st2+=st1[i];
        if (st2[m]=='b') st2[m]='d'; else
        if (st2[m]=='d') st2[m]='b';
        if (st2[m]=='p') st2[m]='q'; else
        if (st2[m]=='q') st2[m]='p';
    }
    if (st1==st2) cout<<"Yes"; else cout<<"No";
    return 0;
}