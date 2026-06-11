#include <bits/stdc++.h>
using namespace std;
#define dhoom ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);  
typedef long long ll;
typedef long double ld;
const ll inf = 1e18;
const int nax = 2e6 + 7;
const ll mod = 1e9 + 7;
//ll tree[4 * nax];
//9uS-22RSwk7gQqh
int count(ll x){
	int cnt = 0;
	while(x != 0){
		cnt++;
		x /= 10;
	}
	return cnt;
}
int main()
{

	int a[] = {1 , 3 , 5, 7 , 8 , 10 , 12};
	int b[] = {4 , 6 , 9 , 11};
	//int c[] = {2};
	int flag = 0;
	int x , y;
	cin >> x >> y;
	int cnt = 0;
	for(int i = 0 ; i < 7 ; i++){
		if(x  == a[i])
			cnt++;
		if(y == a[i])
			cnt++;
	}
	if(cnt == 2)
		flag = 1;
	cnt = 0;
	for(int i = 0 ; i < 4 ; i++){
		if(x  == b[i])
			cnt++;
		if(y == b[i])
			cnt++;
	}
	if(cnt == 2)
		flag = 1;
	if(x == 2 && y == 2)
		flag = 1;
	if(flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
} 


