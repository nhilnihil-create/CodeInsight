#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)


int main()
{
	int64_t N, A, B,aCount=0,bCount=0;
	char M;

	cin >> N >> A >> B;
	
	vector<int64_t> S(100000);
	rep(i, N) {
		cin >> M;
		if (M=='a'&& A+B>0)
		{
			A--;
			cout << "Yes" << endl;

		}
		else if (M == 'b' && B>0 && A+B>0) {
			B--;
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
		
	}
}