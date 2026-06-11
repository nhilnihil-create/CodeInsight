#include "bits/stdc++.h"
using namespace std;



int main() {

	double A, B, C, D, E, F;
	cin >> A >> B >> C >> D >> E >> F;

	int water = 100 * A;
	int sugar = 0;
	double rat = 0;

	int i = 0;
	while (100 * A * i <= F) {
		int j = 0;
		while (100 * (A * i + B * j) <= F) {
			int k = 0;
			while (100 * (A * i + B * j) + C * k <= F) {
				int l = 0;
				while (100 * (A * i + B * j) + C * k + D * l <= F && 100 * (A * i + B * j) + C * k + D * l >= 100*A) {
					double a_i_j_k_l = (100*(C * k + D * l)) / (100 * (A * i + B * j) + C * k + D * l);
					if (C * k + D * l <= E * (A * i + B * j) && a_i_j_k_l > rat) {
						water = 100 * (A * i + B * j) + C * k + D * l;
						sugar = C * k + D * l;
						rat = a_i_j_k_l;
					}
					l++;
				}
				k++;
			}
			j++;
		}
		i++;
	}

	cout << water << " " << sugar;
	
}
