/*------------------------------------ 
........Bismillahir Rahmanir Rahim.... 
..........created by Abdul Aziz....... 
------------------------------------*/ 
#include <iostream> 
#include <algorithm> 
#include <stdio.h> 
#include <cmath> 
#include <vector> 
#include <set> 
#include <map> 
#include <cstring> 
#include <unordered_map> 
#include <queue> 
#define   mod  998244353 
#define   int  long long 
#define   ld   long double 
#define   pb   push_back 
#define   vi  vector<int> 
#define   dbg(x)  cerr << #x << " = " << x << '\n' 
#define   sz(x)  (int)x.size() 
#define   all(a) (a.begin(),a.end()) 
#define   ff   first 
#define   ss   second 
#define   pii  pair<int,int> 
#define   lcm(a,b) (a*b)/__gcd(a,b) 
using namespace std; 
 
int n,k; 
map <int,bool> mp; 
int h[9],l=0,ans=100000000; 
 
void fun(int num){ 
	if (num >= n){
		ans = min(ans,num);
		return;
	}
	for (int i=0;i<l;i++){
		int x=num*10+h[i];
		if (x) fun(x);
	}
} 
 
inline void solve(){ 
    cin >> n >> k ; 
    for (int i=1;i<=k;i++) { 
    	int a; cin >> a; 
    	mp[a] = true; 
    } 
    for (int i=0;i<10;i++) 
    	if (!mp[i]) h[l++] = i; 
    fun(0);
    cout << ans << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
