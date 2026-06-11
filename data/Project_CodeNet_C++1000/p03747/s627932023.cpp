#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int X[100010], W[100010], ans[100010], irek[100010];
vector<int> cw, aw;

int main() {
	ll N, L, T;
	cin >> N >> L >> T;
	for(int i=0; i<N; ++i){
		cin >> X[i] >> W[i];
		if(W[i]==1) cw.emplace_back(i);
		else aw.emplace_back(i);
	}
	if(aw.empty()){
		for(int i=0; i<N; ++i){
			cout << (X[i]+T%L)%L << endl;
		}
	}else if(cw.empty()){
		for(int i=0; i<N; ++i){
			cout << (X[i]+L-T%L)%L << endl;
		}
	}else{
		ll q=((T/L)*2)%N, r=T%L;
		if(r*2>=L){
			q=(q+1)%N;
			r -= (L+1)/2;
		}
		for(int i=0; i<N; ++i){
			if(W[i]==1){
				ans[i]=(X[i]+T%L)%L;
				int t=distance(aw.begin(), upper_bound(aw.begin(), aw.end(), i));
				int ok=-1, ng=aw.size();
				while(ok+1<ng){
					int mid=(ok+ng)/2, dis;
					dis=X[aw[(t+mid)%aw.size()]]-X[i];
					if(dis<0) dis += L;
					if(dis<=r*2) ok=mid;
					else ng=mid;
				}
				irek[(q*aw.size()+ng+i)%N]=i;
			}else{
				ans[i]=(X[i]+L-T%L)%L;
				int t=distance(cw.begin(), upper_bound(cw.begin(), cw.end(), i));
				(t += cw.size()-1) %= cw.size();
				int ok=-1, ng=cw.size();
				while(ok+1<ng){
					int mid=(ok+ng)/2, dis;
					dis=X[i]-X[cw[(t+cw.size()-mid)%cw.size()]];
					if(dis<0) dis += L;
					if(dis<=r*2) ok=mid;
					else ng=mid;
				}
				irek[(i+N-(q*cw.size()+ng)%N)%N]=i;
			}
		}
		for(int i=0; i<N; ++i){
			cout << ans[irek[i]] << endl;
		}
	}
	return 0;
}