#include<bits/stdc++.h>
using namespace std;

const long long INF = 1000000000;

typedef long long ll;

#define writeln(n) cout<<n<<"\n"
#define rep(i,n) for(int i=0; i<(n); ++i)

typedef pair<int, int> P;
typedef pair<string, int> Psi;

int d[5];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int a,b,c,d,e,f;cin>>a>>b>>c>>d>>e>>f;

	int Xmax = a*e;
	int XXmax = b*e;
	int XXXmax =(a+b)*e;

	int Xsugar =0;
	int XXsugar =0;
	int XXXsugar =0;


	for(int i=0; i<=Xmax/c; i++){
		for(int j=0; j<=Xmax/d; j++){
			if(i*c+j*d <=Xmax){
				if(a*100+i*c+j*d<=f){
				Xsugar =max(Xsugar,i*c+j*d);
				}
			}
		}
	}

	for(int i=0; i<=XXmax/c; i++){
		for(int j=0; j<=XXmax/d; j++){
			if(i*c+j*d <=XXmax){
				if(b*100+i*c+j*d<=f){
				XXsugar =max(XXsugar,i*c+j*d);
				}
			}
		}
	}
	for(int i=0; i<=XXXsugar/c; i++){
	for(int j=0; j<=XXXmax/d; j++){
		if(i*c+j*d <=XXXmax){
			if((a+b)*100+i*c+j*d<=f){
				XXXsugar =max(XXXsugar,i*c+j*d);
			}
		}
	}

}

/*	cout<<a*100+Xsugar<<" "<<Xsugar<<endl;
	cout<<b*100+XXsugar<<" "<<XXsugar<<endl;
	cout<<(a+b)*100+XXXsugar<<" "<<XXXsugar<<endl;*/

	if((double)Xsugar/(double)(a*100+Xsugar) >=(double)XXsugar/(double)(b*100+XXsugar)){

		if((double)Xsugar/(double)(a*100+Xsugar) >=(double)XXXsugar/(double)((a+b)*100+XXXsugar)){
		cout<<a*100+Xsugar<<" "<<Xsugar<<endl;
		}else {
			cout<<(a+b)*100+XXXsugar<<" "<<XXXsugar<<endl;
		}
	}else {

		if((double)XXsugar/(double)(b*100+XXsugar) >=(double)XXXsugar/(double)((a+b)*100+XXXsugar)){
		cout<<b*100+XXsugar<<" "<<XXsugar<<endl;
		}else {
			cout<<(a+b)*100+XXXsugar<<" "<<XXXsugar<<endl;
		}
	}


}
