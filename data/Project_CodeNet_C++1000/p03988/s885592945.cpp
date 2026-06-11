#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long int ll;

int main(){
	int n; cin >> n;
	vector<int> a(n);
	map<int,int> mp;
	for(int i=0;i<n;i++){
		cin >> a[i];
		mp[a[i]]++;
	}
	sort(a.begin(),a.end());
	bool ok=1;
	if(a[n-1]%2){
		if(a[0]<(a[n-1]+1)/2)ok=0;
		if(mp[(a[n-1]+1)/2]!=2)ok=0;
		for(int j=(a[n-1]+1)/2;j<=a[n-1];j++){
			if(mp[j]<2)ok=0;
		}
	}else{
		if(a[0]<a[n-1]/2)ok=0;
		if(mp[a[n-1]/2]!=1)ok=0;
		for(int j=(a[n-1]+1)/2+1;j<=a[n-1];j++){
			if(mp[j]<2)ok=0;
		}
	}
	if(ok){
		cout << "Possible" << endl;
	}else{
		cout << "Impossible" << endl;
	}
}