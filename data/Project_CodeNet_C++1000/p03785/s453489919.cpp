#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int,int_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define ordered_set_pair tree<pair<int,int>,int_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update> 
 
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef pair<int,int> pi; 
#define PI 3.1415926535897932384
#define FOR(i,vv,n) for(int i=vv;i<n;i++)
#define FORR(i,n,vv) for(int i=n-1;i>=vv;i--)
#define ve vector 
#define maxind(v) (max_element(v.begin(),v.end())-v.begin())
#define minind(v) (min_element(v.begin(),v.end())-v.begin())
#define maxe(v) *max_element(v.begin(),v.end())
#define mine(v) *min_element(v.begin(),v.end())
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp make_pair
#define M 1000000007ll
#define M1 100000000000000000ll
#define PRECISE cout.precision(18);
#define BS(v,n) binary_search(v.begin(),v.end(),n)
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.begin(),v.end(),greater <int>())
#define F first
#define S second




int main(){

    FAST
//	PRECISE

ll n,c,k;
cin>>n>>c>>k;
ve <ll> time(n,0);
ve <ll> v(n,0);
FOR(i,0,n)
cin>>v[i];
srt(v);
ll ans=0;
ll ma=0;
ll ca=0;

FOR(i,0,n){

if(v[i]>ma){
	ans++;
	ca=1;
	ma=v[i]+k;	
}
else if(ca==c){
	ans++;
	ca=1;
	ma=v[i]+k;
}
else{
	ca++;
}



}
cout<<ans;
return 0;
 }