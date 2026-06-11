#include <bits/stdc++.h>
using namespace std;


int main()
{
	std::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long test;
    test=1;
    // cin>>test;
    while(test--)
    {
        long a,b;
    cin>>a>>b;
    if(a==b)cout<<"Draw";
    else if(a==1 || b==1)
    {
        if(a==1)cout<<"Alice";
        else cout<<"Bob";
    }
    else
    {
        if(a>b)cout<<"Alice";
        else cout<<"Bob";
    }
    
    
    }
}
