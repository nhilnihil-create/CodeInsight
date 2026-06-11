
#include <iostream>
#include<vector>
#include<map>
using namespace std;

int main() {
	long long h,w,n;cin>>h>>w>>n;
	vector<long long> a(n),b(n);
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
//	vector<map<long long,long long>> v;
//	for(int i=0;i<=h;i++){
//		map<long long,long long> m;
//		v.push_back(m);
//	}
	map<long long,map<long long,long long>> v;
	vector<long long> ans(10,0);
	ans[0]=(w-2)*(h-2);
	for(int i=0;i<n;i++){
		for(int j=-1;j<=1;j++){
			for(int k=-1;k<=1;k++){
				long long t=a[i]+j;
				long long y=b[i]+k;
//				cout<<t<<' '<<y<<endl;
				if((t>=2)*(t<=h-1)*(y>=2)*(y<=w-1)){
					ans[v[t][y]]--;
					ans[v[t][y]+1]++;
					v[t][y]++;
				}
			}
		}
	}
	for(int i=0;i<=9;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
