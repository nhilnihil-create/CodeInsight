#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>

#define MOD 1e9+7;
#define INF 1e17+9;
#define PI acos(-1);

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> a(n),b;
	
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(i>=1){
			if(a[i]-a[i-1]!=0){
				b.push_back(a[i]-a[i-1]);
			}	
		}
	}
	
	if(n==1){
		cout << 1 << endl;
		return 0;
	}
	
	int cnt=0;
	for(int i=0;i<b.size()-1;i++){
		if(b[i]>0 && b[i+1]<0 || b[i]<0 && b[i+1]>0){
			cnt++;
			i++;
		}
	}
	
	cout << cnt+1 << endl;
	
	return 0;
}

