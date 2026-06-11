#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long int llint;

int main(){
	llint Q,H,S,D;
	llint N;
	cin >> Q >> H >> S >> D;
	cin >> N;

	llint cost=0;
	{
		llint Ql=Q*8;
		llint Hl=H*4;
		llint Sl=S*2;
		llint Dl=D;
		vector<llint> V={Ql,Hl,Sl,Dl};
		cost += *min_element(V.begin(),V.end())*(N/2);
	}
	{
		llint Ql=Q*4;
		llint Hl=H*2;
		llint Sl=S;
		vector<llint> V={Ql,Hl,Sl};
		cost += *min_element(V.begin(),V.end())*(N%2);
	}
	cout << cost << endl;
	return 0;
}
