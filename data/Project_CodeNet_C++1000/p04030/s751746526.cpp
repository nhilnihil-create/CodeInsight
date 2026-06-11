#include <bits/stdc++.h>
using namespace std;

deque<int> q;
int main(){
	int i,cnt=0;
	string s;
	cin>>s;
	for(i=0;i<s.size();i++){
		if(s[i]=='0'){
			q.push_back(0);
		}
		else if(s[i]=='1'){
			q.push_back(1);
		}
		else
			if(!q.empty()){
				q.pop_back();
			}
	}
	
	while(!q.empty()){
		cout<<q.front();
		q.pop_front();
	}
	return 0;
}