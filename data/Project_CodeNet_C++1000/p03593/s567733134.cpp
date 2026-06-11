#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define REP(i,s,l) for(lli i=s;i<l;i++)
 
signed main(){
 
	lli h,w;
	cin>>h>>w;
 
	char c;
	lli data[26]={0};
	priority_queue<lli> q;
	REP(i,0,h*w){
		cin>>c;
		data[c-'a']++;
	}
	REP(i,0,26) q.push(data[i]);
 
	priority_queue<lli> left;
 
	for(lli i=0;i<(h+1)/2;i++){
		for(lli j=0;j<(w+1)/2;j++){
			lli num=4;
			if(i==(h+1)/2-1 && h%2==1)num /= 2;
			if(j==(w+1)/2-1 && w%2==1)num /= 2;
			left.push(num);
		}
	}
 
	while(left.size()){
		lli leftNow = left.top();
		left.pop();
 
		lli dataNow = q.top();
		q.pop();
		if(leftNow>dataNow){
			/*途中で使いきれなくなったらアウト*/
			cout<<"No"<<endl;
			return 0;
		}
		dataNow -= leftNow;
		q.push(dataNow);
	}
 
	/*最後まで割り当てられればOK*/
	cout<<"Yes"<<endl;
	return 0;
}