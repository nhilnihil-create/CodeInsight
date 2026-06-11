#include <iostream>
using namespace std;

int main() {
	int a,b,c;
	cin>>a>>b>>c;
	if(a==7||a==5)
		if(b==7||b==5)
			if(c==7||c==5)
				if(a+b+c==17)
					cout<<"YES";
	else
	{
		cout<<"NO";
	}
	return 0;
}