#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int A, B, C, D, E, F;
	cin>>A>>B>>C>>D>>E>>F;
	int sug = -1, wat = -1;
	for(int x1 = 0; ; x1++){
		if(100*A*x1 > F)break;
		for(int x2 = 0; ; x2++){
			if(x1 + x2 == 0)continue;
			if(100*(A*x1 + B*x2) > F)break;
			for(int y1 = 0; ; y1++){
				if(100*(A*x1 + B*x2) + C*y1 > F)break;
				for(int y2 = 0; ; y2++){
					if(100*(A*x1 + B*x2) + C*y1 + D*y2 > F)break;
					if(C*y1 + D*y2 <= E*(A*x1 + B*x2)){
						int ts = C*y1 + D*y2;
						int tw = 100*(A*x1 + B*x2);
						if(sug == -1){
							sug = ts; wat = tw;
						}else if(sug*(tw + ts) < ts*(wat + sug)){
							sug = ts; wat = tw;
						}
					}
				}
			}
		}
	}
	cout<<sug + wat<<" "<<sug<<endl;

	return 0;
}