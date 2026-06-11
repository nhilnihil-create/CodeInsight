#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<long long> A(N), S(N);
    for(long long &i: A)
        cin >> i;
    partial_sum(A.begin(), A.end(), S.begin());
	long long ans = INT64_MAX;
	for(int i = 0; i < N - 1; i++)
	{
		ans = min(ans, abs(S[S.size() - 1] - 2 * S[i]));
	}
	cout << ans << endl;
}
