#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    int x,y;cin>>x>>y;
	cout<<abs(abs(x)-abs(y))+((x<0&&y<0)||(x>=0&&y>=0)?(x>=y)*2:1)+(y?0:-1)<<endl;
}