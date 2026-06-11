#include<iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    bool x=false;
    cin>>n;
    while(n>0)
    {
    	if(n%10==9)
    		x=true;
    	n/=10;
    }
    x?	cout<<"Yes":cout<<"No";
}