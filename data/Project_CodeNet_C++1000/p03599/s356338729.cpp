#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <numeric>
#include <cmath>
using namespace std;
typedef long long int ll;
#define all(x) x.begin(),x.end()
const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;
int main()
{
	int a,b,c,d,e,f;
	cin >>a>>b>>c>>d>>e>>f;


	double con = 0.0;
	int water = 0,sugar = 0;
	for(int w = 0; w <=30; w++){
		for(int x = 0; x <= 30; x++){
			for(int y = 0; y <= ceil((double)f/c); y++){
				for(int z = 0; z <= ceil((double)f/d); z++){
					int water_weight = a*w+b*x, sugar_weight = c*y+d*z;
					int total = 100*water_weight + sugar_weight;
					if(total <= f && sugar_weight <= water_weight*e){
						if(con < (double)sugar_weight/total){
							con = (double)sugar_weight/total;
							water = 100*water_weight;
							sugar = sugar_weight;
						}
					}
				}
			}
		}
	}
 	if(con == 0) water = 100*a;

	cout << water+sugar << " " << sugar << endl;

	return 0;
}