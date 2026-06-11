#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int e,f;
int solve(int limit){
	int ret = 0;
	for(int i=0; i<=limit/c; i++){
		for(int j=0; j<=limit/d; j++){
			int sugar = c*i+d*j;
			if(sugar>limit) continue;
			ret = max(ret,sugar);
		}
	}
	return ret;
}
int main(){
	cin>>a>>b;
	a*=100;
	b*=100;
	cin>>c>>d>>e>>f;
	int maxmass=a;
	int maxsugar=0;
	
	for(int i=0; i<=30; i++){
		for(int j=0; j<=30; j++){
			int water = i*a+j*b;
			if(water>f) continue;
			int sugar_limit = min(water/100*e,f-water);
			int sugar_mass=solve(sugar_limit);
			int total = water+sugar_mass;
			if(sugar_mass*maxmass>total*maxsugar){
				maxmass = total;
				maxsugar = sugar_mass;
			}
		}
	}
	cout<<maxmass<<" "<<maxsugar;
}