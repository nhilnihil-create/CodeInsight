#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	deque<int>deq;
	for(int i=0; i<n; i++){
		if(i%2==0) deq.push_front(arr[i]);
		else deq.push_back(arr[i]);
	}
	if(n%2==0){
		while(deq.size()){
			cout<<deq.back()<<" ";
			deq.pop_back();
		}
	}
	else{
		while(deq.size()){
			cout<<deq.front()<<" ";
			deq.pop_front();
		}
	}
}