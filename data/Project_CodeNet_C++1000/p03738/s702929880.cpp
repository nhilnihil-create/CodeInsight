#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	string a,b;
	cin >> a >> b;
	int lena = a.size();
	int lenb = b.size();
	if(lena > lenb){
		cout << "GREATER" << endl;
		return 0;
	}
	else if(lena < lenb){
		cout << "LESS" << endl;
		return 0;
	}
	else{
		rep(i,lena){
			if((a[i]) - '0' > (b[i]) - '0'){
				cout << "GREATER" << endl;
				return 0;
			}else if((a[i]) - '0' < (b[i]) - '0'){
				cout << "LESS" << endl;
				return 0;
			}
		}
	}
	cout << "EQUAL" << endl;
}