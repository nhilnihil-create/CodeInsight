#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <algorithm>
#define abs(a,b) a<b?b-a:a-b
using namespace std;
long long a,b,c,d,e,m,n,ma,le,ri,mid,p[1080130],q[5],r[105],i,t;
string s[5];
char k;
int su(int a)
{int i;
	if(a==1||a==0)return 0;
	for(i=2;i<=a;i++)
	{
		if(a-i>0&&(a-i)%2==0&&i%2==0)return 1;
	}
	return 0;
}
int main() 
{long long to=0;
	for(i=0;i<3;i++)
    cin>>q[i];
    sort(q,q+3);
	if(q[0]-q[1]==q[1]-q[2])cout<<"YES";
	else cout<<"NO";    
    return 0;
}