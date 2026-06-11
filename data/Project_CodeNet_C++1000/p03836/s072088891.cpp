#include<bits/stdc++.h>
using namespace std;

#define mod      1e9+7;
#define INF      1e9+9;
#define ps(x,y)  fixed<<setprecision(y)<<x
# define PI 3.14159265358979323846264338327950 L
typedef long long ll;
typedef unsigned long long ull;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	string s1,s2,s3,s4;
	int d1=x2-x1,d2=y2-y1;
	while(d1--){
		s3+='L';
		s4+='R';
	}
	while(d2--){
		s1+='U';
		s2+='D';
	}
	cout<<s1<<s4<<s2<<s3;
	cout<<'L'<<s1<<'U'<<s4<<"RD";
	cout<<'R'<<s2<<'D'<<s3<<"LU\n";
	return 0;
}