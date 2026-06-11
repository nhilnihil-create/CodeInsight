#define rep(i, n) for(int i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using P = pair<int, int>;

int main() {
	int A,B,C,D,E,F;;
	cin >> A >> B >> C >> D >> E >> F;
	vector<int> cand_water, cand_sugar;
	for (int i=0;100*A*i<=F;i++) 
		for (int j=0;100*A*i+100*B*j<=F;j++)
			cand_water.push_back(100*A*i+100*B*j);
	int max_sugar = E*F/100;
	for (int i=0;C*i<=max_sugar;i++)
		for (int j=0;C*i+D*j<=max_sugar;j++)
			cand_sugar.push_back(C*i+D*j);
	double noudo = 0;
	int ans_water, ans_sugar;
	ans_water, ans_sugar = 0, 0;
	for (int water : cand_water){
		for (int sugar : cand_sugar) {
			if ((water+sugar>0) && (water+sugar<=F) && (E*water>=100*sugar)) {
				double cand_noudo = double(100*sugar)/double(sugar+water);
				if(noudo<=cand_noudo) {
					noudo = cand_noudo;
					ans_water = water;
					ans_sugar = sugar;
				}
			}
		}
	}
	printf("%d %d\n", ans_water+ans_sugar, ans_sugar);
	return 0;
}
