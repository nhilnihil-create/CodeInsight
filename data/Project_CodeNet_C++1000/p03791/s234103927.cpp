#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long ary[100010];
vector<long long> vec;
int main(){
	long long N;
	cin>>N;
	for(long long i=1;i<=N;i++){
		cin>>ary[i];
	}
	for(long long i=1;i<=N;i++){
		if((ary[i]+1)/2<(i-vec.size())){
			vec.push_back(i-vec.size());
		}
	}
	long long noko=N-vec.size();
	long long res=1;
	for(vector<long long>::iterator it=vec.begin();it!=vec.end();it++){
		res=(res*(*it))%1000000007;
	}
	for(long long i=1;i<=noko;i++){
		res=(res*i)%1000000007;
	}
	cout<<res<<endl;
	return 0;
}
