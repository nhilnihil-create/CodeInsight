#include <iostream>
using namespace std;

int num[105];
int main() {
	int N, mx=0; cin >> N;
	for(int i=0; i<N; ++i){
	    int a;
	    cin >> a;
	    ++num[a];
	    mx=max(mx, a);
	}
	bool flag=true;
	for(int i=1; i<=mx; ++i){
	    if(i*2<=mx-1){
	        if(num[i]>0) flag=false;
	    }
	    else if(i==(mx+1)/2){
	        if(num[i]!=mx%2+1) flag=false;
	    }
	    else if(num[i]<2) flag=false;
	}
	cout << (flag ? "Possible" : "Impossible") << endl;
	return 0;
}
