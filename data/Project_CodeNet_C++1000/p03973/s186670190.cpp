
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
#define REP(i, a,b) for(i=a;i<b;i++) 
#define output(x) cout<<x<<endl;
typedef long long int ll;



int main()
{
	ll  i, j, k, l, m, sum, flag,ans,W,H,N;
	sum = 0;
	flag = 0;
	cin >> N;
	vector<ll>A(N);
	REP(i, 0, N) {
		cin >> A[i];
	}
	j = 1;
	sum += A[0] - 1;
	REP(i, 1, N) {
		if (A[i] == j + 1) {
			j++;
		}
		else {
			sum += (A[i] - 1) / (j + 1);
		}
	}
	output(sum);

	return 0;
}

