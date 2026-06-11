#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
typedef long long LL;
const LL mod = 1e9 + 7;
// head
const int maxn = 1e5 + 5;
int n, a[maxn], pos;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	cin>>n;
	rep(i, 1, n)
	    cin>>a[i];
	sort(a + 1, a + n + 1, cmp);
	rep(i, 0, n) 
	    if(i >= a[i + 1]) {
	    	int j = i - 1;
	    	while(i - 1 < a[j + 2]) j++;
	    	if((j - i + 2)%2 == 0 || (a[i] - (i - 1))%2 == 0) cout<<"First"<<endl;
	    	else cout<<"Second"<<endl;
	    	break;
	    }
} 