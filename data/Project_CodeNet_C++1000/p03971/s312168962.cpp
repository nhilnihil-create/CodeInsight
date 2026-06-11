#include<bits/stdc++.h>
using namespace std;
int main() {
	int N, A, B; cin >> N >> A >> B;
	string s; cin >> s;
	int dome = 0, overs = 0;
	string res[N];
	for (int i = 0; i < N; i++)
	{
		if(s[i] == 'c') res[i] = "No";
		else if(s[i] == 'a') {
			if(dome + overs < A + B) {
				res[i] = "Yes";
				dome++;
			}
			else res[i] = "No";
		}
		else if(s[i] == 'b') {
			if(dome + overs < A + B && overs < B) {
				res[i] = "Yes";
				overs++;
			}
			else res[i] = "No";
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		cout << res[i] << endl;
	}
	
	return 0;
}
