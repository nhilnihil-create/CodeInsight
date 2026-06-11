#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
using namespace std;

long long H,W,N;

bool in_area(long long x, long long y){
	return x >=1 && y >= 1 && x+2 <= H && y+2 <= W;
}

int main(){
	while(cin >> H >> W >> N){
		vector< pair<long long,long long> > v(N+10);
		vector< pair<long long,long long> > s;
		set < pair<long long,long long> > S;
		long long ans[10] = {0};
		for(int i=0;i<N;i++){
			int a, b;
			cin >> a >> b;
			v[i] = make_pair(a,b);
		}
		for(int i=0;i<v.size();i++){
			for(int k=0;k<3;k++){
				for(int l=0;l<3;l++){
					if(in_area(v[i].first-k,v[i].second-l)){
						s.push_back(make_pair(v[i].first-k,v[i].second-l));
						S.insert(make_pair(v[i].first-k,v[i].second-l));
					}
				}
			}
		}
		if(s.size()!=0){
			sort(s.begin(),s.end());
			long long j = 0, count = 1;
			while(j<=s.size()-2){
				if(s[j] == s[j+1]){
					count++;
					j++;
				}else{
					ans[count]++;
					count = 1;
					j++;
				}
			}
			ans[count]++;
		}
		ans[0] = (H-2)*(W-2) - S.size();
		for(int i=0;i<10;i++){
			cout << ans[i] << endl;
		}
	}
}