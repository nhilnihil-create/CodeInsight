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

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	int sum=0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		sum+=a[i];
	}
	sort(a.begin(),a.end());
	if(sum%10!=0){
		cout << sum << endl;
		return 0;
	}else{
		for(int i=0;i<n;i++){
			int temp=sum-a[i];
			if(temp%10!=0){
				cout << temp << endl;
				return 0;
			}
		}
	}
	cout << "0" << endl;
	return 0;
}