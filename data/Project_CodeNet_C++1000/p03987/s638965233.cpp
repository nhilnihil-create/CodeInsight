#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int , int> ii;
typedef pair<ii , int> iii;
ll n , x[300000] , memo[300000] , memor[300000] , t;
ll sum;
stack<int>st , str;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> x[i];
	}
	for(int i = 1 ; i <= n ; i++){
		if(!st.empty()){
			while(st.top() > x[i]){
				t = st.top();
				memo[x[i]] += memo[t];
				st.pop();
				if(st.size() == 0)break;
			}
		}
		memo[x[i]]++;
		st.push(x[i]);
	}
	for(int i = n ; i >= 1 ; i--){
		if(!str.empty()){	
			while(str.top() > x[i]){
				t = str.top();
				memor[x[i]] += memor[t];
				str.pop();
				if(str.size() == 0)break;
			}
		}
		memor[x[i]]++;
		str.push(x[i]);
	}
	sum = 0;
	for(int i = 1 ; i <= n ; i++){
		sum += (memo[i]*memor[i])*i;
	}
	cout << sum;
}