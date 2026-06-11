#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int sx,sy,tx,ty;
	cin >> sx >> sy >> tx >> ty;
	int x = tx - sx;
	int y = ty - sy;

	for(int i  =0;i<y;i++)
	{
		cout<<'U';
	}
	for(int i = 0;i<x+1;i++)
	{
		cout<<'R';
	}
	for(int i = 0;i<y+1;i++)
	{
		cout<<'D';
	}
	for(int i = 0;i<x+1;i++)
	{
		cout<<'L';
	}
	cout<<'U';
	for(int i =0;i< x;i++)cout<<'R';
	for(int i = 0;i<y+1;i++)cout<<'U';
	for(int i =0;i<x+1;i++)cout<<'L';
	for(int i =0 ;i<y+1;i++)cout<<'D';
	cout<<'R'<<endl;;
}