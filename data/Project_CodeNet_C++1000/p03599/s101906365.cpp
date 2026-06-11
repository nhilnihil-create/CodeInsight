#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



double calc_density( int water, int sugar ){
	return 100.0 * (double)sugar / (double)( water + sugar );
}



int main(){
	int A, B, C, D, E, F;
	cin >> A >> B >> C >> D >> E >> F;
	
	// memo: w * 100 = water
	vector<int> possible_w(31);
	for ( int a = 0; a <= 30; a++ ){
		for ( int b = 0; b <= 30; b++ ){
			int w = a*A+b*B;
			if ( 0 < w && w <= 30 )
				possible_w[w] = 1;
		}
	}
	
	
	double best_density = -1.0;
	int best_water;
	int best_sugar;
	
	for ( int w = 0; w <= 30; w++ ){
		if ( !possible_w[w] )
			continue;
		int water = w*100;
		int max_sugar = min( w * E, F - water );
		
		for ( int c = 0; c*C <= max_sugar; c++ ){
			int d = (max_sugar - c*C)/D;
			int sugar = c*C+d*D;
			double density = calc_density( water, sugar );
			if ( best_density < density ){
				best_water = water;
				best_sugar = sugar;
				best_density = density;
			}
		}
		
		
	}
	
	cout << (best_water+best_sugar) << " " << best_sugar << endl;
	
	return 0;
}
