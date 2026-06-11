#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n,m;cin>>n>>m;
	vector<long long> a(n),start(m+1,0);
	vector<pair<int,long long>> end(m+1,make_pair(0,0));
	long long sum=0;
	long long minus,temp=0;
	long long num=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i!=n-1){
			start[a[i]]++;
		}
		if(i!=0){
			end[a[i]].first++;
			long long add=a[i]-a[i-1];
			if(add<0){
				add+=m;
				if((a[i]>a[0])+(a[0]>a[i-1])){
					num++;
					if(a[0]>a[i-1]){
						temp+=a[0]-a[i-1];
					}else{
						temp+=a[0]-a[i-1]+m;
					}
				}
			}else{
				if((a[i-1]<a[0])*(a[0]<a[i])){
					num++;
					temp+=a[0]-a[i-1];
				}
			}
			end[a[i]].second+=add;
			sum+=add;
		}
	}
	temp+=end[a[0]].second;
	num+=end[a[0]].first;
	temp-=num;
	minus=temp;
	int a0=a[0];

	sort(a.begin(),a.end());
	int i=0;
	while(a[i]<a0)i++;
	do{
//		cout<<a[i]<<' '<<temp<<' '<<num<<endl;
		temp-=end[a[i]].second;
		temp+=num;
		num-=end[a[i]].first;
		num+=start[a[i]];
		temp-=num;
		long long ex=i;
		while(a[i]==a[ex]){
			i++;
			if(i==n)i=0;
		}
//		cout<<i<<endl;
		long long add=a[i]-a[ex];
		if(add<0)add+=m;
		temp+=num*add;
		if(minus<temp)minus=temp;


	}while(a[i]!=a0);
	long long ans=sum-minus;
//	cout<<sum<<endl;
//	cout<<minus<<endl;
	cout<<ans<<endl;


	return 0;
}