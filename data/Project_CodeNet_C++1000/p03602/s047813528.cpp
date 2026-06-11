#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
int N;
ll G[301][301] = {0};
ll A[301][301] = {0};
bool F[301][301];


int main(){
	cin >> N;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin >> A[i][j];
			G[i][j] = A[i][j];
		}
	}
	for(int k=1;k<=N;k++){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				G[i][j] = min(G[i][j],G[i][k]+G[k][j]);
			}
		}
	}
	bool judge = true;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(A[i][j]!=G[i][j]) judge = false;
		}
	}
	if(!judge) cout << -1 << endl;
	else{
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				F[i][j] = true;
			}
		}
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				if(i!=j){
					for(int k=1;k<=N;k++){
						if(k!=i && k != j && G[i][j]==G[i][k]+G[k][j]){
							F[i][j] = false;
						}
					}
				}
			}
		}
		ll ans = 0;
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				if(F[i][j]) ans += G[i][j];
			}
		}
		cout << ans/2 << endl;
	}
}