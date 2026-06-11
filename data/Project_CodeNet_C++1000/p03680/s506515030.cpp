#include<bits/stdc++.h>
#define ll long long int
#define vl vector<ll>
#define pb push_back
using namespace std;
int main()
{
    ll t,tp,mx=0,c=0,n,i,j,k;
        cin >> n;
        vl v(n+1,0);
        for(i=1;i<=n;i++)
        cin >> v[i];
        set<ll> s;
        s.insert(1);c=0;
        i=1;
        while(true)
        {
        	c++;
        	if(v[i]==2)
        	break;
        	i=v[i];
        	if(s.count(i))
        	{
        		c=-1;
        		break;
        	}
        	else
        	{
        		s.insert(i);
        	}
        }
        cout << c ;
        
    
    return 0;
}