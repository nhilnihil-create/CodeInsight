#include<iostream>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<algorithm>//min,max,swap,rand,reverse,sort,lower_bound
#include<functional>
#include<vector>
#include<list>
#include<map>
#include<tuple>
#include<cmath>//abs, sin, cos
#include<bitset>
using namespace std;

int main()
{
	int N, A, B;
	int up = 0;
	int rank = 1;
	string S;
	cin >> N >> A >> B;
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'a' && up < (A + B)) {
			cout << "Yes" << endl;
			up++;
		}
		else if (S[i] == 'b' && up < (A + B) && rank <= B) {
			rank++;
			cout << "Yes" << endl;
			up++;
		}
		else
			cout << "No" << endl;
	}
	return 0;
}