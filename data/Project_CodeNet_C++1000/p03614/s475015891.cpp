#include <iostream>
#include <vector>
using namespace std;

int N;
int main(){
	cin >> N;
	vector<int> v(N+1,0);
	bool A[N+2] = {false};
	for(int i=1;i<=N;i++){
		cin >> v[i];
		if(v[i]==i) A[i] = true;
	}
	int j=1;
	int count = 0,ans = 0;
	while(j<=N+1){
		if(A[j]) count++;
		else{
			ans += (count+1)/2;
			count = 0;
		}
		j++;
	}
	cout << ans << endl;
}