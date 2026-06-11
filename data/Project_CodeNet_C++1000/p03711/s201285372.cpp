//Date and time of submission: 
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
ll a,b;
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cin>>a>>b;
	if(a==2||b==2)
	{
	    cout<<"No";
	    return 0;
	}
	else if(a==1||a==3||a==5||a==7||a==8||a==10||a==12)
	{
	    if(b==1||b==3||b==5||b==7||b==8||b==10||b==12)
	    {
	        cout<<"Yes";
	        return 0;
	    }
	    else
	    {
	        cout<<"No";
	        return 0;
	    }
	}
	else
	{
	    if(b==4||b==6||b==9||b==11)
	    cout<<"Yes";
	    else
	    cout<<"No";
	}
	return 0;
}
