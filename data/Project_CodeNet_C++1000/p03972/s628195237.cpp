#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll,int> P; 

int H,W;
ll p;
int main(){
	cin >> W >> H;
	vector<P> v(W+H);
	for(int i=0;i<W+H;i++){
		cin >> p;
		if(i<W) v[i] = P(p,1);
		else v[i] = P(p,-1);
	}
	sort(v.begin(),v.end());
	int X = H+1,Y = W+1;
	ll ans = 0;
	int i = 0;
	while(X>0 && Y>0 && i<H+W){
		if(v[i].second==1 && X>0){
			ans += v[i].first*X;
			Y--;
		}else if(v[i].second==-1 && Y>0){
			ans += v[i].first*Y;
			X--;
		}
		i++;
	}
	cout << ans << endl;
}