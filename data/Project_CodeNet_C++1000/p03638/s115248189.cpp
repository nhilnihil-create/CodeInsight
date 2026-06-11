#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	int h,w,n;
	cin>>h>>w>>n;
	vector<int> col(n);
	for(int i=0;i<n;i++) cin>>col.at(i);

	vector<vector<int>> grid(h,vector<int>(w));

	for(int i=0;i<h;i++){
		int j=0;
		if(i%2==1) j=w-1;

		while(0<=j && j<w){
			int C=distance(col.begin(),upper_bound(col.begin(),col.end(),0))+1;
			grid.at(i).at(j)=C;
			col.at(C-1)--;

			if(i%2==0) j++;
			else j--;
		}
	}

	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cout<<grid.at(i).at(j);
			if(j<w-1) cout<<" ";
			else cout<<endl;
		}
	}

	return 0;
}
