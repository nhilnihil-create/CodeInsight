#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>

#define MOD 1e9+7;
#define INF 1e17+9;
#define PI acos(-1);

using namespace std;

void calc_plus(long long &sum,long long &cost,long long &a){
	cost+=(1-sum);
	a+=cost;
	sum=1;
}

void calc_minus(long long &sum,long long &cost,long long &a){
	cost+=(sum-(-1));
	a-=cost;
	sum=-1;
}

int main(){
	long long n;
	cin >> n;
	vector<long long> a(n,0),b(n,0),c(n,0);
	
	for(long long i=0;i<n;i++){
		cin >> a[i];
		c[i]=b[i]=a[i];
	}
	//+-+-
	long long cost_p=0,sum_p=0;
	for(long long i=0;i<n;i++){
		sum_p+=b[i];
		//1,3,5・・・奇数を１にする
		if(i%2==0){
			if(sum_p<0)calc_plus(sum_p,cost_p,b[i]);
		}
		//2,4,6・・・偶数を-１にする
		if(i%2==1){
			if(sum_p>0)calc_minus(sum_p,cost_p,b[i]);
		}
		//丁度0になった場合
		if(sum_p==0){
			cost_p++;
			if(i%2==0){
				sum_p=1;
				b[i]++;
			}else{
				sum_p=-1;
				b[i]--;
			}
		}
	}
	//-+-+
	long long cost_m=0,sum_m=0;
	for(long long i=0;i<n;i++){
		sum_m+=c[i];
		//1,3,5・・・奇数を-１にする
		if(i%2==0){
			if(sum_m>0)calc_minus(sum_m,cost_m,c[i]);
		}
		//2,4,6・・・偶数を１にする
		if(i%2==1){
			if(sum_m<0)calc_plus(sum_m,cost_m,c[i]);
		}
		//丁度0になった場合
		if(sum_m==0){
			cost_m++;
			if(i%2==0){
				sum_m=-1;
				c[i]--;
			}else{
				sum_m=1;
				c[i]++;
			}
		}
	}
	long long ans=min(cost_p,cost_m);
	cout << ans << endl;
	return 0;
}

