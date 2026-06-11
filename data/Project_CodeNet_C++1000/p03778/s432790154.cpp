#include <bits/stdc++.h>
using namespace std;


int main() {
int a,b,c;
cin >> a>>b >>c;

if(-min(b,c)-a+max(b,c) < 0){
	cout << 0 <<endl;
}
else{
	cout << -min(b,c)-a+max(b,c) <<endl;
}

}
