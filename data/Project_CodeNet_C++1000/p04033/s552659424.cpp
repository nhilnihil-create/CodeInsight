#include<iostream>
#include<cmath>
#include<algorithm>
#define loop(i, a, b) for(i=a; i<=b; i++)
#define MOD 1000000007
#define ll long long
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a, b;
	cin >> a >> b;
	//cout << re << endl;
	if(a>0 && b>0) cout << "Positive\n";
	else if(a<=0 && b>=0) cout << "Zero\n";
	else{
		if((b-a)%2) cout << "Positive\n";
		else cout << "Negative\n";
	}
	return 0;
}
