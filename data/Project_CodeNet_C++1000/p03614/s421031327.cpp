#include<bits/stdc++.h>
using namespace std;
 
#define P(p) cout<<(p)<<endl
#define rep(i,m,n) for(int i = (m); i < (int)(n); i++)
#define rrep(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define vsort(v) sort(v.begin(), v.end());
#define rvsort(v) sort(v.begin(), v.end(),greater<int>());
#define YES cout<<"YES"<< endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl  
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
#define ret return
#define lb(v,n) lower_bound(v.begin(),v.end(),n)
#define ub(v,n) upper_bound(v.begin(),v.end(),n)
#define mae(v) max_element(v.begin(),v.end())
#define mie(v) min_element(v.begin(),v.end())
#define INF 0x7FFFFFFF
#define mod 1000000007
typedef long long ll;
////////////////////////////////////////////////////////////

int main(){
	int n;
	cin >> n;
	int p[100000]={};
	rep(i,0,n){
		cin >> p[i];
		p[i]--;
	}

	int cnt=0;
	
	if(p[0] == 0 ){
		swap(p[0],p[1]);
		cnt++;
	}

	rep(i,0,n-1){
		if(	p[i+1] == i+1 ){
			swap(p[i] , p[i+1] );
			cnt++;
			i++;
		}
	}
	
	cout << cnt << endl;

	ret 0;
}