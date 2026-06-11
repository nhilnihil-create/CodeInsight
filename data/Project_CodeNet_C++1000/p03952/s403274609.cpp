#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;

int main(){
	int N, x; cin >> N >> x;
	if(N != 2){
		if(x == 1 || x == 2*N-1) cout << "No" << "\n";
		else{
			cout << "Yes" << "\n";
			int ans[2*N-1];
			if(x != 2*N-2){
				ans[N-2] = x+2;
				ans[N-1] = 1;
				ans[N] = x;
				ans[N+1] = x+1;
				vector<int> arr;
				for(int i=2; i<=2*N-1; i++){
					if(i<x || i>x+2) arr.push_back(i);
				}
				for(int i=0; i<N-2; i++) cout << arr[i] << endl;
				for(int i=N-2; i<N+2; i++) cout << ans[i] << endl;
				for(int i=N+2; i<2*N-1; i++) cout << arr[i-4] << endl;
			}else{
				ans[N-2] = 1;
				ans[N-1] = 2*N-2;
				ans[N] = 2*N-1;
				ans[N+1] = 2;
				vector<int> arr;
				for(int i=3; i<=2*N-3; i++){
					arr.push_back(i);
				}
				for(int i=0; i<N-2; i++) cout << arr[i] << endl;
				for(int i=N-2; i<N+2; i++) cout << ans[i] << endl;
				for(int i=N+2; i<2*N-1; i++) cout << arr[i-4] << endl;
			}
		}
	}else{
		if(x == 1 || x == 3) cout << "No" << "\n";
		else{
			cout << "Yes" << "\n";
			for(int i=1; i<=3; i++) cout << i << "\n";
		}
	}
	return 0;
}
