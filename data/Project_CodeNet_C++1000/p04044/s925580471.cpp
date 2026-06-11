#include <bits/stdc++.h>
 
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<long long>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sll set<long long>
#define si set<int>
#define sti stack<int>
#define stkl stack<ll>
#define qi queue<int>
#define pb push_back
#define ff first
#define ss second
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const ll mod=1e9+7;
using namespace std;
int c=0;

void solve(){
	int n,l;
	cin>>n>>l;
	vector<string> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];

	sort(a.begin(), a.end());

	for(auto i:a)
		cout<<i;
	cout<<endl;

}
 
int main(){
    IOS;
    int q=1;
    //cin>>q;
    while(q--){
    	c++;
        solve();
    }
}
