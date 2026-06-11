#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int a,b,c,count=0;
	cin >> a >> b >> c;
	int tempa,tempb,tempc;
	set<tuple<int,int,int> > s;
	tuple<int, int, int> triple;
	while (true) {
		if (a%2!=0 || b%2 != 0|| c%2!=0) {
			cout << count;
			break;
			}
		
		tempa=a;tempb=b;tempc=c;
		a = tempb/2 + tempc/2;
		b = tempa/2 + tempc/2;
		c = tempa/2 + tempb/2;
		if (s.count(make_tuple(a,b,c))){
			cout << -1;
			break;}
		count ++;
		s.emplace(a,b,c);
		}
}
