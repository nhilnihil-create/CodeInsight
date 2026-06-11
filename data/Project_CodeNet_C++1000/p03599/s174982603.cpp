#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using P = pair<int,int>;
using ll = long long;
static const int INF = 1000000000;
static const ll MOD = 1000000007;

ll gcd(ll a, ll b){return b!=0 ? gcd(b, a%b) : a;}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}

int main(){
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	
	vector<int> water;
	for(int i = 0; i <= 30; ++i){
		for(int j = 0; j <= 30; ++j){
			int water_tmp = (a * i + b * j) * 100;
			if(water_tmp <= f && water_tmp != 0){
				water.push_back(water_tmp);
			}
		}
	}
	
	water.erase(unique(water.begin(), water.end()), water.end());
	
	vector<int> sugar;
	for(int i = 0; i <= 100; ++i){
		for(int j = 0; j <= 100; ++j){
			int sugar_tmp = c * i + d * j;
			if(sugar_tmp <= f){
				sugar.push_back(sugar_tmp);
			}
		}
	}
	
	sugar.erase(unique(sugar.begin(), sugar.end()), sugar.end());
	
  	//rep(i, water.size()) cout << water[i] << " ";
    //cout << endl;
    //rep(i, sugar.size()) cout << sugar[i] << " ";
    //cout << endl;
  
	double noudo = -1.0;
	int ans_water = 0;
	int ans_sugar = 0;
	for(int i = 0; i < water.size(); ++i){
		for(int j = 0; j < sugar.size(); ++j){
			if(water[i] + sugar[j] > f) continue;
			if(100 * sugar[j] > water[i] * e) continue;
			if(noudo < (double)sugar[j] * 100.0 / ((double)water[i] + (double)sugar[j])){
				noudo = (double)sugar[j] * 100.0 / ((double)water[i] + (double)sugar[j]);
				ans_water = water[i];
				ans_sugar = sugar[j];
			}
		}
	}
	
	cout << ans_water+ans_sugar << " " << ans_sugar << endl;
	
	return 0;
}

