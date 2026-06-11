#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <stack>
#include <string>
#include <cstring>
#include <numeric>
#include <iomanip>
using namespace std;
//
const int inf=1e9+7;//0x3f
//
int main(){
	int W,H;
	long long P[100000],Q[100000];
	vector<pair<long long,int>> V;
	cin>>W>>H;
	for(int i=0;i<W;i++){
		cin>>P[i];
		V.push_back(make_pair(P[i],i));
	}
	for(int i=0;i<H;i++){
		cin>>Q[i];
		V.push_back(make_pair(Q[i],i+W));
	}
	sort(V.begin(),V.end());
	int w=W+1,h=H+1;
	long long ans=0;
	for(int i=0;i<V.size();i++){
		if(V[i].second>=W){
			ans+=w*V[i].first;
			h--;
		}else{
			ans+=h*V[i].first;
			w--;
		}
	}
	cout<<ans<<endl;
	return 0;
}