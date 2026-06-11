#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
#define INF 1e9
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef vector < pair<int, int> > vii;
typedef long double ld;
typedef tree<pair<int,int>, null_type, less<pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;
 
ll n, m, x, cnt_odd[100001], cnt[100001], ans;
 
int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> x;
		cnt[x]++;
		if(cnt[x]%2){
			cnt_odd[x%m]++;
		}
		else{
			cnt_odd[x%m]--;
		}
	}
	if(m%2==0){
		x=0;
		for(int i = 0; i*m <= 100000; i++){
			x+=cnt[i*m];
		}
		ans+=x/2;
		x=0;
		for(int i = 0; i*m+m/2 <= 100000; i++){
			x+=cnt[i*m+m/2];
		}
		ans+=x/2;
		for(int i = 1; i < m/2; i++){
			x=min(cnt_odd[i],cnt_odd[m-i]);
			cnt_odd[i]-=x;
			cnt_odd[m-i]-=x;
			ans+=x;
			if(cnt_odd[i]==0 && cnt_odd[m-i]==0){
				for(int j = 0; i+j*m<=100000; j++){
					ans+=cnt[i+j*m]/2;
				}
				for(int j = 0; m-i+j*m<=100000; j++){
					ans+=cnt[m-i+j*m]/2;
				}
			}
			else if(cnt_odd[i]==0){
				for(int j = 0; i+j*m <= 100000; j++){
					if(cnt[i+j*m]%2){
						cnt[i+j*m]--;
					}
					x=min(cnt_odd[m-i],cnt[i+j*m]);
					ans+=x;
					cnt_odd[m-i]-=x;
					cnt[i+j*m]-=x;
					ans+=cnt[i+j*m]/2;
				}
				for(int j = 0; m-i+j*m <= 100000; j++){
					ans+=cnt[m-i+j*m]/2;
				}
			}
			else{
				for(int j = 0; m-i+j*m <= 100000; j++){
					if(cnt[m-i+j*m]%2){
						cnt[m-i+j*m]--;
					}
					x=min(cnt_odd[i],cnt[m-i+j*m]);
					ans+=x;
					cnt_odd[i]-=x;
					cnt[m-i+j*m]-=x;
					ans+=cnt[m-i+j*m]/2;
				}
				for(int j = 0; i+j*m <= 100000; j++){
					ans+=cnt[i+j*m]/2;
				}
			}
		}
	}
	else{
		x=0;
		for(int i = 0; i*m <= 100000; i++){
			x+=cnt[i*m];
		}
		ans+=x/2;
		for(int i = 1; i <= m/2; i++){
			x=min(cnt_odd[i],cnt_odd[m-i]);
			cnt_odd[i]-=x;
			cnt_odd[m-i]-=x;
			ans+=x;
			if(cnt_odd[i]==0 && cnt_odd[m-i]==0){
				for(int j = 0; i+j*m<=100000; j++){
					ans+=cnt[i+j*m]/2;
				}
				for(int j = 0; m-i+j*m<=100000; j++){
					ans+=cnt[m-i+j*m]/2;
				}
			}
			else if(cnt_odd[i]==0){
				for(int j = 0; i+j*m <= 100000; j++){
					if(cnt[i+j*m]%2){
						cnt[i+j*m]--;
					}
					x=min(cnt_odd[m-i],cnt[i+j*m]);
					ans+=x;
					cnt_odd[m-i]-=x;
					cnt[i+j*m]-=x;
					ans+=cnt[i+j*m]/2;
				}
				for(int j = 0; m-i+j*m <= 100000; j++){
					ans+=cnt[m-i+j*m]/2;
				}
			}
			else{
				for(int j = 0; m-i+j*m <= 100000; j++){
					if(cnt[m-i+j*m]%2){
						cnt[m-i+j*m]--;
					}
					x=min(cnt_odd[i],cnt[m-i+j*m]);
					ans+=x;
					cnt_odd[i]-=x;
					cnt[m-i+j*m]-=x;
					ans+=cnt[m-i+j*m]/2;
				}
				for(int j = 0; i+j*m <= 100000; j++){
					ans+=cnt[i+j*m]/2;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
