#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long int ll;

int main()
{
	int A,B,C,D,E,F;
	cin>>A>>B>>C>>D>>E>>F;
	int a = 100*A;
	int b = 100*B;
	vector<int> alpha;
	vector<int> beta;
	for(int i = 0; a*i <= F; i++){
		for(int j = 0; a*i + b*j <= F; j++){
			alpha.push_back(a*i + b*j);
		}
	}
	sort(alpha.begin(),alpha.end());
	alpha.erase(unique(alpha.begin(),alpha.end()),alpha.end());
	/*for(auto iter = alpha.begin(); iter != alpha.end(); iter++){
		cout<<*iter<<endl;
	}*/
	for(int i = 0; C*i <= F; i++){
		for(int j = 0; C*i + D*j <= F; j++){
			beta.push_back(C*i + D*j);
		}
	}
	sort(beta.begin(),beta.end());
	beta.erase(unique(beta.begin(),beta.end()),beta.end());
	

	int maxAlpha = 0;
	int maxBeta = 0;
	double maxConcentration = 0;
	for(auto iterA = alpha.begin(); iterA != alpha.end(); iterA++){
		for(auto iterB = beta.begin(); iterB!= beta.end(); iterB++){
			if( (*iterA + *iterB <= F) && (*iterA * E) >= (100*(*iterB))){
				double concentration = 0;
				if( *iterA + *iterB != 0){
					concentration = (double)(*iterB) / (double)(*iterA + *iterB);
					//cout<<"alpha + beta: "<<*iterA + *iterB<<", concentration:"<<concentration<<endl;
				}
				if( concentration > maxConcentration){
					maxAlpha = *iterA;
					maxBeta = *iterB;
					maxConcentration = concentration;
				}
			}
		}
	}
	if( maxAlpha == 0 && maxBeta == 0){
		cout<<min(a,b)<<" "<<0<<endl;
	}else{
		cout<<maxAlpha+maxBeta<<" "<<maxBeta<<endl;
	}

	return 0;
}
