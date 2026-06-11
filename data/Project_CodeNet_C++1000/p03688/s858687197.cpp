#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define SP << " " 
#define LLi long long int

using namespace std;

//vector<LLi>を出力
void PV(vector<int> pvv) {
	rep(i, (int)pvv.size()-1) cout << pvv[i] SP;
	cout<< pvv[(int)pvv.size()-1] <<endl;
}

int main(){

	int n, l=0, lm=0, sm=0;
	vector<int> a;
	cin>> n;
  
  	a.resize(n);
  	rep(i, n){
      	cin>> a[i];
      //if(a[i]!=99997) cout<< a[i] <<endl;
      	l=max(l, a[i]);
    }
  
  //cout<< "l=" << l <<endl;
  
  	rep(i, n){
      	if(a[i]==l) lm++;
      	if(a[i]==l-1) sm++;
    }
  
  //cout<< "lm=" << lm << " sm=" << sm <<endl;
  
  	if(n!=lm+sm){
      	cout<< "No" <<endl;
      	return 0;
    }
  
  	if(sm==0){
      	if(l==1){
      		cout<< "Yes" <<endl;
      		return 0;
    	}
  		if(l==n-1){
      		cout<< "Yes" <<endl;
      		return 0;
    	}
  		if(l*2<=n) cout<< "Yes" <<endl;
      	else cout<< "No" <<endl;
      	return 0;
    }
  
  	if(l==2 && 1<sm){
      	cout<< "No" <<endl;
      	return 0;
    }
  
  	//if(sm<=l-1 && lm<=2*n-l) cout<< "Yes" <<endl;
  	if(sm<=l-1 && l<=sm+lm/2) cout<< "Yes" <<endl;
    else cout<< "No" <<endl;
  
     return 0;
}