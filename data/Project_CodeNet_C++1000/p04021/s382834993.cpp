//daydream
#include <bits/stdc++.h>
using namespace std;
long long n,m,k,a1[100005],a2[100005],tmp,sum=0;
string s;
char r1,r2,op;
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	long long cnt1=0,cnt2=0;
	for (int i=1;i<=n;i++){
		if (i%2){
			cnt1++;
			cin>>a1[cnt1];
		}
		else{
			cnt2++;
			cin>>a2[cnt2];
		}
	}
	sort(a1+1,a1+cnt1+1);
	sort(a2+1,a2+cnt2+1);
	long long cnt11=1,cnt22=1;
	for (int i=1;i<=n;i++){
		if (cnt11>cnt1){
			for (int j=i;j<=n;j++){
				if (j%2==1) sum++;
			}
			break;
		}
		else if (cnt22>cnt2){
			for (int j=i;j<=n;j++){
				if (j%2==0) sum++;
			}
			break;
		}
		if (a1[cnt11]<a2[cnt22]){
			cnt11++;
			if (i%2==0) sum++;
		}
		else if (a2[cnt22]<a1[cnt11]){
			cnt22++;
			if (i%2==1) sum++;
		}
	}
	/*for (int i=1;i<=cnt1;i++) cout<<a1[i]<<' ';
	cout<<endl;
	for (int i=1;i<=cnt2;i++) cout<<a2[i]<<' ';
	cout<<endl;*/
	cout<<(sum+1)/2<<endl;
	return 0;
}