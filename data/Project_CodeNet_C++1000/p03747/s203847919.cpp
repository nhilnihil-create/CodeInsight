#include <iostream>
#include <algorithm>
#define ll long long int

using namespace std;

int main(int argc, char const* argv[])
{
	int n, l, t;
	cin >> n >> l >> t;
	ll *x = new ll[n];
	int *w = new int[n];
	for(int i = 0; i < n; i++){
			cin >> x[i] >> w[i];
			w[i] = 3 - 2 * w[i];
			x[i] = x[i] + w[i] * t;
	}

	int ini = 0;
	if(w[0] == 1){
			for(int i = 1; i < n; i++){
					if(w[i] == -1 && x[i] < x[0]){
							ini += (x[0] - x[i] + l - 1) / l;
					}
			}
			ini = ini % n;
	}else{
			x[0] += l;
			for(int i = 1; i < n; i++){
					if(w[i] == 1 && x[i] > x[0]){
							ini -= (x[i] - x[0] + l - 1) / l;
					}
			}
			x[0] -= l;
			ini = ini % n;
			if(ini < 0)ini += n;
	}
	int iniv = x[0] % l;
	if(iniv < 0)iniv += l;
	for(int i = 0; i < n; i++){
			x[i] = x[i] % l;
			if(x[i] < 0)x[i] += l;
	}
	sort(x, x + n);
	int flag = 0;
	for(int i = 0; i < n; i++){
			if(x[i] == iniv){
					if(w[0] == 1){
							flag = i;
							break;
					}else{
							if(i < n - 1 && x[i + 1] == iniv){
									continue;
							}
							flag = i;
							break;
					}
			}
	}
	for(int i = 0; i < n; i++){
			cout << x[(flag - ini + n + i) % n] << endl;
	}
	return 0;
}
