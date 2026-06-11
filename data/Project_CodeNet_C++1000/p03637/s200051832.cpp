#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int even=0;
	int four=0;
	int odd=0;

	for(int i=0;i<n;i++){
		int hoge;
		cin>>hoge;

		if(hoge%4==0) four++;
		else if(hoge%2==0) even++;
		else odd++;
	}

	if(even%2==1){
		even--;
		odd++;
	}

	if(four>=odd-1) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

	return 0;
}
