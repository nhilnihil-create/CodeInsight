#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 10;
int n;
int a[MAXN];
bool cmp(int x , int y){
	return x > y;
}
int main(){
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 1 ; i <= n ; ++ i)
		cin >> a[i];
	sort(a + 1 , a + n + 1 , cmp);
	int cur = n;
	for(int i = 1 ; i <= n ; ++ i)
		if(i > a[i]){
			cur = i - 1;
			break;
		}
	if(cur != n && a[cur + 1] == cur){
		int tmp = cur + 1;
		while(tmp < n && a[tmp + 1] == cur)
			tmp ++;
		if(((tmp - cur) & 1)){
			cout << "First" << endl;
			return 0;
		}
	}
	cout << (((a[cur] - cur) & 1) ? "First" : "Second") << endl;
	return 0;
}