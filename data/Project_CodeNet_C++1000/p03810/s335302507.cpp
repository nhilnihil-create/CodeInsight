#include<bits/stdc++.h>
using namespace std;

int mygcd(int x,int y){
	while((x%=y)&&(y%=x));
	return x^y;
}

int a[100000];

int play(int n){
	int odd=0,even=0;
	for(int i=0;i<n;i++)
		if(a[i]&1)	odd++;
		else	even++;
	if(even&1)	return 0;
	else if(odd>=2)	return 1;
	else	return 2;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	if(n==1)	return cout<<"Second"<<endl, 0;
	while(true) {
		int res = play(n);
		if(res==2){
			bool invalid = false; 
			for(int i=0;i<n;i++)
				if(a[i]&1) {
					a[i]--;
					if(a[i]==0)	invalid=true;
					break;
				}
			if(invalid)	{
				cnt++;
				break;
			}
			int g = a[0];
			for(int i=1;i<n;i++)
				g = mygcd(g,a[i]);
			for(int i=0;i<n;i++)
				a[i]/=g;
			cnt++;
		}
		else{
			cnt+=res;
			break;
		}
	}
	if(cnt&1)
		cout<<"Second"<<endl;
	else
		cout<<"First"<<endl;
}
