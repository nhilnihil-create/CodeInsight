#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> stick(n);
	priority_queue<int> hoge;

	for(int i=0;i<n;i++) cin>>stick.at(i);

	sort(stick.begin(),stick.end());

	int cnt=1;
	int now=stick.at(0);

	for(int i=1;i<n;i++){
		if(stick.at(i)==now) cnt++;
		else cnt=1;
		now=stick.at(i);

		if(cnt==2){
			hoge.push(now);
			cnt=0;
		}
	}

	if(hoge.size()<2){
		cout<<0<<endl;
		return 0;
	}

	long long one=hoge.top();
	hoge.pop();
	long long two=hoge.top();

	cout<<one*two<<endl;

	return 0;
}
