#include<bits/stdc++.h> 
using namespace std;
char k;
int main()
{
    for(int i=1;i<=12;i++)
    {
        cin>>k;
        if(i<=3 || i>4)cout<<k;
    	else cout<<k<<" ";
    }
	cout<<endl;
    return 0;
}