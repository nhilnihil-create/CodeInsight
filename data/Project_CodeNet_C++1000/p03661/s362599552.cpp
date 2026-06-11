//周♂雨扬是最强的！！！
//大佬祝您AK
//沈哲♂贝是最强的！！！
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<fstream>
using namespace std;
//ifstream fin(.in);
//ofstream fout(.out);
long long n,num[400003];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		num[i]=num[i]+num[i-1];
	}
	long long ans=999999999999;
	for(int i=2;i<=n;i++){
		ans=min(ans,abs(num[n]-num[i-1]-num[i-1]));
	}
	cout<<ans<<endl;
	return 0;
}
//沈♂哲贝是最强的！！！
//大佬祝您AK
//周♂雨扬是最强的！！！