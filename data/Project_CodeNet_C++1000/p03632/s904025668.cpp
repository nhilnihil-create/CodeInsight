#include<bits/stdc++.h>
using namespace std;

using v1 = vector<int>;
using v2 = vector<vector<int>>;
using ll = long long;

int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
 	int time;
	if(c>=b || a>=d){
		time = 0;
	}else{
		time = min(b, d) - max(a,c);
	}
	cout << time << endl;

}
