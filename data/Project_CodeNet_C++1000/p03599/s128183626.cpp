#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	double concentration = 0;
	int s_mass = 0;
	int mass =0;
	for(int i = 0; i <= f/(100*a); i++){
		for(int j = 0; j<= f/(100*b); j++){
			if((i*a+j*b)*100>f) break;
			if(i ==0 && j==0) continue;
			for(int k = 0; k<=((e*(i*a+j*b))/c); k++){
				if(((i*a+j*b)*100+k*c) >f) break;
				for(int l=0; l<=((e*(i*a+j*b))/d); l++){
					if((i*a+j*b)*100+ k*c + l*d >f) break;
					if((k*c + l*d)> (i*a+j*b)*e) break;
					double sugar = static_cast<double>(100*(l*d + k*c));
					double v_con = sugar/(l*d + k*c + (i*a+j*b)*100);
					if(concentration < v_con){
						concentration = v_con;
						s_mass = (l*d + k*c);
						mass = (l*d + k*c + (i*a+j*b)*100);
					}
				}
			}
		}
	}
	if(s_mass == 0) mass = 100*a;
	cout << mass << " " << s_mass << endl;
}
