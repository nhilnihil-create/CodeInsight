#include <iostream>
#include <string>
#define llint long long 

using namespace std;

string s, t;
llint S, T;
llint sumS[100005], sumT[100005];
llint Q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s >> t;
	S = s.size(), T = t.size();
	s = "#" + s, t = "#" + t;
	
	for(int i = 1; i <= S; i++){
		sumS[i] = sumS[i-1];
		if(s[i] == 'A') sumS[i]++;
		else sumS[i] += 2;
	}
	for(int i = 1; i <= T; i++){
		sumT[i] = sumT[i-1];
		if(t[i] == 'A') sumT[i]++;
		else sumT[i] += 2;
	}
	
	cin >> Q;
	llint a, b, c, d;
	for(int i = 0; i < Q; i++){
		cin >> a >> b >> c >> d;
		if((sumS[b]-sumS[a-1]) % 3 == (sumT[d]-sumT[c-1])%3) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}