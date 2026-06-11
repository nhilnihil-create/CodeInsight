#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	
	int ent, fvs=0, svs=0;
	for(int i=0 ; i<3 ; i++){
		cin>>ent;
		if(ent==5)	fvs++;
		else if(ent==7)	svs++;
	}
	cout<<(fvs==2 && svs==1?"YES":"NO")<<"\n";
	
	return 0;
	}