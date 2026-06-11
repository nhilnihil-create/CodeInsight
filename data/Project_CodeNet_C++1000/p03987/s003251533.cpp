#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 200000;
int Tree[4* MAX];
void build(vector<int> &ar,int i , int l ,int r )
{
	if( l == r)
	{
		Tree[i] = l;
		return ; 
	}
	int mid = (l + r)/2;
	build(ar, i * 2 , l, mid);
	build(ar, i *2 + 1, mid + 1, r);
	Tree[i] = min(ar[Tree[i * 2]] , ar[Tree[i * 2 + 1]]) == ar[Tree[i * 2]] ? Tree[i * 2] : Tree[i * 2 +1];
}
int query(vector<int> &ar, int i, int l , int r , int tl ,int tr)
{
	if( tl > tr)
	{
		return -1;
	}
	if( tl == l && tr == r)
	{
		return Tree[i];
	}
	int mid = (l + r)/2;
	int left = query(ar, i * 2, l , mid, max(tl, l), min(tr, mid));
	int right = query(ar, i * 2 + 1, mid + 1, r, max(tl, mid + 1), min(tr, r));
	if(left != -1 && right != -1)
	{
		return min(ar[left], ar[right]) == ar[left] ? left : right;
	}
	return left != -1 ? left : right;
}
int solve(vector<int> &ar, int st, int end )
{
	if( st >= end)
		return 0;
	if( st == end - 1)
	{
		return ar[st];
	}
	int minn = query(ar, 1, 0, ar.size()-1, st, end -1);
	int res = ar[minn] * (minn - st + 1) * (end - minn );
	res += solve(ar, st, minn) + solve(ar, minn + 1, end);
	return res; 
}
int32_t main(){
	int n ;
	cin >> n ;
	vector<int> ar(n);
	for(int i =0 ; i<n ; i++)
	{
		cin >> ar[i];
	}
	build(ar, 1, 0, n-1);
	cout<< solve(ar, 0 , n)  <<endl;
}