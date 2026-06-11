#include<bits/stdc++.h>
using namespace std;
int main()
{   int a,b,c,s1,s2 ;
    cin>>a>>b>>c;
    s1=abs(c-a);
   s2=abs(b-a);
    if(s2>s1)
        cout<<"B";
    else
        cout<<"A";
	return 0;
}

