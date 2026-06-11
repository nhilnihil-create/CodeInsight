#include <bits/stdc++.h>
using namespace std;

int main() {
	int a,b,c;
	cin >> a >> b >> c;
  
  	vector<int> check(3);
  		check.at(0)=a;
		check.at(1)=b;
		check.at(2)=c;
  	sort(check.begin(),check.end());
  
  	if(check.at(2)==check.at(0)+check.at(1)){
      cout << "Yes" <<endl;
    }
    else
      cout << "No" <<endl;
  
}
