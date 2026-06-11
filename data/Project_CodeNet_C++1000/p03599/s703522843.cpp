#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	vector<int> wa(0);
	vector<int> sh(0);
	for(int i=0; i>=0; i++){
		if(100*a*i >= f) break;
		for(int j=0; j>=0; j++){
			if(100*a*i+100*b*j >= f) break;
			wa.push_back(100*a*i+100*b*j);
		}
	}
	sort(wa.begin(), wa.end());
	for(int i=0; i>=0; i++){
		if(c*i*100 > f*e) break;
		for(int j=0; j>=0; j++){
			if((c*i+d*j)*100 > f*e) break;
			sh.push_back(c*i+d*j);
		}
	}
	sort(sh.begin(), sh.end());
	vector<int> w(0);
	vector<int> s(0);
	rep(i, wa.size()-1) if(wa.at(i+1) != wa.at(i)) w.push_back(wa.at(i+1));
	rep(i, sh.size()-1) if(sh.at(i+1) != sh.at(i)) s.push_back(sh.at(i+1));
	double ma = 0;
	int answs = w.at(0);
	int anss = 0;
	rep(i, w.size()){
		rep(j, s.size()){
			int ws = w.at(i) + s.at(j);
			double wsd = w.at(i) + s.at(j);
			if(ws > f) continue;
			double r = s.at(j);
			r *= 100;
			r /= w.at(i);
			double ed = e;
			if(r > ed) continue;
			if(r > ma){
				ma = r;
				answs = ws;
				anss = s.at(j);
			} 
		}
	}
	cout << answs << ' ' << anss << endl;
	return 0;
}
