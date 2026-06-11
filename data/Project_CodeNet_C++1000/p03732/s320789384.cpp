#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <cmath>
#include <limits>
#include <utility>
#include <map>
#include <iomanip>


#define rep(p,q) for(int i = p;i < q;i++)
#define ll long long

using namespace std;

const int cons = 1e9 + 7;

//60D
int main(void) {
	vector<ll> w0 = vector<ll>();
	vector<ll> w1 = vector<ll>();
	vector<ll> w2 = vector<ll>();
	vector<ll> w3 = vector<ll>();
	ll n, w;
	cin >> n >> w;
	ll wf, vf;
	cin >> wf >> vf;
	w0.push_back(vf);
	rep(1, n) {
		ll wi, vi;
		cin >> wi >> vi;
		switch (wi - wf)
		{
		case 0:
			w0.push_back(vi);
			break;
		case 1:
			w1.push_back(vi);
			break;
		case 2:
			w2.push_back(vi);
			break;
		case 3:
			w3.push_back(vi);
			break;
		default:
			break;
		}
	}

	sort(w0.rbegin(), w0.rend());
	sort(w1.rbegin(), w1.rend());
	sort(w2.rbegin(), w2.rend());
	sort(w3.rbegin(), w3.rend());


	ll ans = 0;
	for (int i3 = 0; i3 <= w3.size(); i3++) {
		for (int i2 = 0; i2 <= w2.size(); i2++) {
			for (int i1 = 0; i1 <= w1.size(); i1++) {
				for (int i0 = 0; i0 <= w0.size(); i0++) {
					ll ansCo = 0;
					if (i0*wf + i1*(wf + 1) + i2*(wf + 2) + i3*(wf + 3) <= w) {
						rep(0, i0)if(i < w0.size())ansCo += w0[i];
						rep(0, i1)if (i < w1.size())ansCo += w1[i];
						rep(0, i2)if (i < w2.size())ansCo += w2[i];
						rep(0, i3)if (i < w3.size())ansCo += w3[i];
						ans = max(ans, ansCo);
					}
				}
			}
		}
	}
	cout << ans << endl;
}