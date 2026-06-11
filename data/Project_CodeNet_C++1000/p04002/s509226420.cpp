#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
lli h, w, n, a, b;
set<pair<lli, lli>> st;
lli answers[10];

//Returns how many marked squares there are in rows r-1 to r+1 intersection columns c-1 to c+1
int checkGrid(lli r, lli c) {
	int retVal = 0;
	for(int i = r-1; i <= r+1; i++) for(int j=c-1; j<=c+1; j++) if(st.find(make_pair(i, j)) != st.end()) retVal++;
	return retVal;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> h >> w >> n;
	for(int i = 0; i<10; i++) answers[i]=0;
	answers[0] = (h-2)*(w-2);	

	for(int i = 0; i < n ; i++) {
		cin >> a >> b;
		a--; b--;
		for(int j=a-1; j<=a+1; j++) {
			if(j<=0 || j>=h-1) continue;
			for(int k=b-1; k<=b+1; k++) {
				if(k<=0 || k>=w-1) continue;
				int oldVal = checkGrid(j, k);
				answers[oldVal]--;
				answers[oldVal+1]++;
			}
		}
		st.insert(make_pair(a, b));
	}

	for(int i=0; i<10; i++) cout << answers[i] << endl;

	return 0;
}