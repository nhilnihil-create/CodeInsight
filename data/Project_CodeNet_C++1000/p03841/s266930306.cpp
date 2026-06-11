#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, int> p[510];
int ans[250010], beh[510];

int main() {
	int N;
	cin >> N;
	for(int i=0; i<N; ++i){
		int x;
		cin >> x;
		p[i]=make_pair(x, i+1);
	}
	sort(p, p+N);
	for(int i=0; i<N; ++i){
		ans[p[i].first]=p[i].second;
		int cnt=1;
		for(int j=1; j<p[i].first && cnt<p[i].second; ++j){
			if(ans[j]==0){
				ans[j]=p[i].second;
				++cnt;
			}
		}
		if(cnt<p[i].second){
			cout << "No" << endl;
			return 0;
		}
	}
	int ys=0;
	for(int i=1; i<=N*N; ++i){
		if(p[ys].first==i){
			beh[p[ys].second]=N-p[ys].second;
			++ys;
		}
		if(ans[i]==0){
			for(int j=1; j<=N; ++j){
				if(beh[j]>0){
					ans[i]=j;
					--beh[j];
					break;
				}
			}
			if(ans[i]==0){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	cout << ans[1];
	for(int i=2; i<=N*N; ++i) cout << ' ' << ans[i];
	cout << endl;
	return 0;
}