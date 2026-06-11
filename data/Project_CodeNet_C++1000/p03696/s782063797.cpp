#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	int n;
	string s;
	cin>>n>>s;

	int cnt=0;
	int l=0;
	int r=0;

	for(int i=0;i<n;i++){
		if(s.at(i)=='(') cnt++;
		else cnt--;
		if(cnt<0){
			l++;
			cnt=0;
		}
	}

	r=cnt;

	for(int i=0;i<l;i++){
		s="("+s;
	}

	for(int i=0;i<r;i++){
		s+=")";
	}

	cout<<s<<endl;

	return 0;
}
