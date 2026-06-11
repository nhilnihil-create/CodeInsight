#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 100;
int arr[N],b[N];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	unordered_map<int, int> pos;
    int n;
    cin >> n;
    for(int i = 1;i <=  n;i++)cin >> arr[i],b[i] = arr[i],pos[arr[i]] = i;
  	sort(b + 1,b + 1 + n);
  	int ans = 0;
  	for(int i = 1;i <= n;i++){
  	    if((i % 2) != (pos[b[i]]) % 2){
  	        ans++;
  	    }
  	}
  	cout << (ans / 2);
  	return 0;
} 