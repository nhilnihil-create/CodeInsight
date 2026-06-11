#include<iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include<map>
#include<cstring>
#include<iomanip>
#include <string>
#include <vector>	
#include<unordered_map>
#include<unordered_set>
using namespace std;


typedef long long unsigned llu;
typedef long double ld;
#define ll long long
#define PI 3.14159265358979323846
#define For(i, a, b) for (int i = a, sz = (int)b; i < sz; i++)
#define rFor(i, a, b, c) for (int i = (a); i >= (b); i -= (c))
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define fill(a, b) memset(a, b, sizeof(a))
#define IO ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0)
const int mod = 1000000007;
const ll inf = 1000000000009;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b) { return a*b/gcd(a,b);}

//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdoutn

int n{},ans{};
int vis[100005];
vector<int>v(n);
int solve(int size,int i)
{
	if(i==2)return ans;
	if(!vis[i] && i<size){
		ans++;
		vis[i]=1;
		int a=solve(size,v[i]);
		return a;
	}
	else return -1;
}


int main()
{
	IO;
	cin>>n;
	v.resize(n+1);
	For(i,1,n+1)cin>>v[i];
	cout<<solve(n+1,1)<<'\n';

	//system("pause");
	return 0;
}