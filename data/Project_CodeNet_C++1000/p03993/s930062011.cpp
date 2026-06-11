#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long int llint;

int main(){
	int N;
	cin >> N;
	int A[N+1];
	for(int i=1;i<=N;i++){
		cin >> A[i];
	}
	int cnt=0;
	for(int i=1;i<=N;i++){
		if(A[A[i]]==i){
			cnt++;
		}
	}
	cnt/=2;
	cout << cnt << endl;
	return 0;
}
