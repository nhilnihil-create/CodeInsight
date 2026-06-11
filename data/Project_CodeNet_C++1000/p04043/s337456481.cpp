#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	vector<int > v;
	int a,b,c;
	cin >> a >> b >> c;
	int cnt5 = 0;
	int cnt7 = 0;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	int p = v.size();
	for(int i=0;i<p;++i){
		if(v[i]==5){
			cnt5++;
		}
		else if(v[i]==7){
			cnt7++;
		}
	}
	if(cnt5==2 && cnt7 ==1){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}	
	return 0;
}
