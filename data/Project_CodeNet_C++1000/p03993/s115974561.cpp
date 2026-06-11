#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef unsigned long long ll;
int main(){
 
int N; cin >> N;
vector<int> a(N);
for(int i = 1; i <= N;i++) cin >> a[i];
int count = 0;
for(int i = 1; i <= N; i++){
	if(a[a[i]] == i){
		count++;
	}
}
cout << count / 2<< endl;
}