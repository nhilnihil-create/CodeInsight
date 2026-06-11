#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
string N;
cin >> N[0] >> N[1] >> N[2];
int countf = 0, counts = 0;

for (int i = 0; i < 3; i++) {
	if (N[i] == '5') ++countf; 
	else if (N[i] == '7') ++counts; 
}

if (countf == 2 && counts ==1) cout << "YES" << endl;
else cout << "NO" << endl;

	return 0;
}
