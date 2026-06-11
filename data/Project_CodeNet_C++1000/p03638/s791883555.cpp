#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 100000000000000

int main(){
	int h,w,n;cin>>h>>w>>n;//n:塗り分ける色の種類   h*wマス
	
	priority_queue<int> que;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		for(int j=0;j<a;j++){
			que.push(i);
		}
	}//queに色iをa個push

	vector<vector<int>> c(h,vector<int>(w,0));

	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			int num=que.top();
			que.pop();
			if(i%2==0){
				c[i][j]=num;
			}else{
				c[i][w-1-j]=num;
			}
		}
	}

	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cout<<c[i][j]+1<<" ";
		}
		cout<<endl;
	}

	return 0;
}