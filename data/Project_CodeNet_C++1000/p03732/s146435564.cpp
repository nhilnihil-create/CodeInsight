#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
vector<pi>item;
vector<ll>values[4];
int main(){
	for(int i=0; i<4; i++) values[i].push_back(0);
	int n;
	ll w;
	cin>>n>>w;
	for(int i=0; i<n; i++){
		ll ww,v;
		cin>>ww>>v;
		item.push_back(pi(ww,v));
	}
	sort(all(item));
	ll most_light = item[0].first;
	reverse(all(item));
	for(int i=0; i<item.size(); i++){
		values[item[i].first-most_light].push_back(item[i].second);
	}
	for(int i=0; i<4; i++){
		for(int j=1; j<values[i].size(); j++){
			values[i][j]+=values[i][j-1];
		}
	}
	long long maxval = 0;
	long long unit = most_light;
	for(int i=0; i<values[0].size(); i++){
		long long val1 = values[0][i];
		for(int j=0; j<values[1].size(); j++){
			long long val2 = values[1][j];
			for(int p=0; p<values[2].size(); p++){
				long long val3 = values[2][p];
				for(int q=0; q<values[3].size(); q++){
					long long val = values[3][q];
					val+=(val1+val2+val3);
					long long weight = unit*i;
					weight+=(unit+1)*j;
					weight+=(unit+2)*p;
					weight+=(unit+3)*q;
					if(weight<=w) maxval = max(maxval,val);
				}
			}
		}
	}
	cout<<maxval;
}