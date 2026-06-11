#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;cin>>n;
	vector<long long> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	a.push_back(0);
	vector<pair<long long,int>> v(n),v2(n);
	pair<long long,int> p;
	for(int i=0;i<n;i++){
		p.first=-a[i];
		p.second=i;
		v[i]=p;
	}
	vector<int> num;
	vector<long long> sum;
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++){
		v[i].first*=-1;
	}
	num.push_back(v[0].second);
	sum.push_back(0);
	int highest=v[0].second;
	for(int i=1;i<n;i++){
		if(v[i].second<highest){
			num.push_back(v[i].second);
			highest=v[i].second;
		}

	}
	num.push_back(n);
//	for(int i=0;i<num.size();i++){
//		cout<<num[i]<<' ';
//	}
//	cout<<endl;
	vector<long long> ans(n,0);
	int j=0;
	int numsum=0;
//	for(int i=0;i<n;i++){
//		cout<<v[i].first<<' '<<v[i].second<<endl;
//	}
	for(int i=0;i<num.size()-1;i++){
		long long sum=0;
		sum+=numsum*(a[num[i]]-a[num[i+1]]);
		while(v[j].second!=num[i+1]){
			sum+=v[j].first-a[num[i+1]];
			numsum++;
			j++;
			if(j==n)break;
		}
		ans[num[i]]=sum;
	}
	for(int i=0;i<n;i++){
		cout<<ans[i]<<endl;
	}

	return 0;
}