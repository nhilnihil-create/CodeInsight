#include<bits/stdc++.h>

using namespace std;

const int mxk = 1e5 + 10;

int n, a[mxk];
bool lose = 0;

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
    sort(a + 1, a + n + 1, greater<int>());
    for(int i = 1; i <= n; ++i)
        if (i + 1 > a[i + 1]) {
            int j = 0;
            while(a[j + i + 1] == i) 
				++j;
            if (((a[i] - i) & 1) || (j & 1))
				cout << "First" << endl;
            else 
				cout << "Second" << endl;
            break;
        }
    return 0;
}