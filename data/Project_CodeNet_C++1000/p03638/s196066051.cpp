#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

int main() {
	int h,w,n;cin>>h>>w>>n;
	
	int b[n];
	rep(i,n)cin>>b[i];
	
	vector<int>c;
	rep(i,n){
	    rep(j,b[i])c.push_back(i+1);
	}

	int a[h][w];
	rep(i,h){
	    rep(j,w){
	        a[i][j]=c[i*w + j];
	    }
	}
	
	int ar[h][w];
	rep(i,h){
	    rep(j,w){
	        if(i%2==0)ar[i][j]=a[i][j];
	        else ar[i][j]=a[i][w-1-j];
	    }
	}
	rep(i,h){
	    rep(j,w-1){
	        cout<<ar[i][j]<<" ";
	    }
	    cout<<ar[i][w-1]<<endl;
	}
	
	return 0;
}