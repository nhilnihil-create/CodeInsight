#include <iostream>
#include <algorithm>
using namespace std;

int N,ans[251000] = {0};
pair<int,int> X[510];
int main(){
	cin >> N;
	int x;
	for(int i=1;i<=N;i++){
		cin >> x;
		X[i] = {x,i};
		ans[x] = i;
	}
	sort(X+1,X+N+1);
	int id = 1;
	bool judge = true;
	for(int i=1;i<=N;i++){
		int count = 0;
		while(count<X[i].second-1){
			if(ans[id]==0){
				ans[id] = X[i].second;
				count++;
			}
			id++;
		}
	}
	id = N*N;
	for(int i=N;i>=1;i--){
		int count = 0;
		while(count<N-X[i].second){
			if(ans[id]==0){
				ans[id] = X[i].second;
				count++;
			}
			id--;
		}
	}
	int c[510] = {0},num = 1;
	for(int i=1;i<=N*N;i++){
		c[ans[i]]++;
		if(i==X[num].first){
			if(c[X[num].second]!=X[num].second) judge = false;
			num++;
		}
	}
	if(!judge){
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	for(int i=1;i<=N*N;i++){
		cout << ans[i] << (i!=N*N? " ":"\n");
	}
}
