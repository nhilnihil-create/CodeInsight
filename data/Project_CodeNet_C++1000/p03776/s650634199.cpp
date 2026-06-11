#include <bits/stdc++.h>


#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
const int MD = (int)1e9 + 7; typedef vector<ll> VL;
void dbg(){ cerr << "\n"; }  template <class T, class ...T2>
void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }
template <class T, class T2> void amin(T& a,T2 b){ if(a > b) a = b;}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n, a, b;
	cin >>n >>a >>b;
	VL v(n);
	rep(i, n) cin >>v[i];
	
	VI np = {n/3 , n/3 ,n/3}; np[2]= n-np[0]-np[1];
	VI gt ={ 0, np[0], np[0]+np[1]};
	//for(auto x :np) cerr<<x<<" "; dbg("");
	vector<VL> zsm(3, VL(55)), zct(3, VL(55));

	auto fnc=[&](int p)->void{
		int n=np[p];
		rep(i, 1<<n){
			int ct = __builtin_popcount(i); ll sm = 0;
			rep(j, n) if(i>>j & 1) sm += v[gt[p] + j];
			if(zsm[p][ct] < sm){ zsm[p][ct] = sm; zct[p][ct] = 1;}
			else if(zsm[p][ct] == sm) zct[p][ct]++;
		}
	};

	rep(i, 3) fnc(i);
	VL qsm(55), qct(55);
	rep(i, np[0]+1) rep(j, np[1]+1) rep(k, np[2]+1){
		int zz = i+j+k;
		if( zz >=a && zz <=b ){
			ll psm = zsm[0][i] +zsm[1][j] +zsm[2][k];
			ll pct = zct[0][i] *zct[1][j] *zct[2][k];
			
			if(qsm[zz] < psm && pct > 0){
				qsm[zz] = psm; qct[zz] = pct;
			}else if(qsm[zz] == psm) qct[zz] += pct;
		}
	}
	double mx=0; int svi=-1;
	rep2(i, a, b+1) if(mx < (double)qsm[i] / i){
		mx = (double)qsm[i] / i; svi =i;
	}
	ll ans = 0;
	rep2(i, a, b+1){
		if(qsm[svi] * i == qsm[i] * svi) ans += qct[i];
	}
	printf("%.12f\n%lld\n", mx, ans);

	return 0;
}
