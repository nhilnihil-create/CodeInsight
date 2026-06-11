
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
	ll  i, j, k, l, m, sum, flag,ans,W,H;
	sum = 0;
	flag = 0;
	cin >> W >> H;
	vector<ll>P(W);
	vector<ll>Q(H);
	vector<pair<ll,char>>A(W + H);
	ll  I, J;
	I= 0;
	J = 0;
	REP(i, 0, W) {
		cin >> P[i];
		A[i].first = P[i];
		A[i].second = 'i';
	}
	REP(i, 0, H) {
		cin >> Q[i];
		A[i+W].first = Q[i];
		A[i+W].second = 'j';
	}
	sort(A.begin(), A.end());
	i = 0;
	REP(i, 0, W + H) {
		if (A[i].second == 'i') {
			sum += A[i].first*(H + 1 - J);
			I++;
		}
		else {
			sum += A[i].first*(W + 1 - I);
			J++;

		}
	}
	output(sum);
	

	return 0;
}

