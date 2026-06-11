#include <bits/stdc++.h>
using namespace std;

int main(){
	int W,H;
	cin >> W >> H;
	vector<pair<long long,int>> pq;
	for(int i=0;i<W;i++){
		pair<long long,int> p;
		cin >> p.first;
		p.second=1;
		pq.push_back(p);
	}
	for(int i=0;i<H;i++){
		pair<long long,int> q;
		cin >> q.first;
		q.second=2;
		pq.push_back(q);
	}
	
	sort(pq.begin(),pq.end());
	
	long long ans=0;
	int x=0,y=0;
	
	for(int i=0;i<H+W;i++){
		if(pq[i].second==1){
			x++;
			ans+=pq[i].first*(long long)(H-y+1);
		}
		else{
			y++;
			ans+=pq[i].first*(long long)(W-x+1);
		}
	}
	cout << ans << endl;
	return 0;
}