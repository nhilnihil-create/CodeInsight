#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e6 + 5;



int n;
string s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>n;
    cin>>s;


    auto print_ans = [](vector<int> v) {
	for (int x: v) {
	    cout<<(x==0? 'W': 'S');
	}
	cout<<endl;
    };

    for (int a=0;a<2;a++) {
	for (int b=0;b<2;b++) {
	    vector<int> ans(n);
	    ans[0]=a;
	    ans[1]=b;
	    bool ok = true;
	    for (int i=1; i<n-1; i++) {
		if (s[i]=='o') {
		    ans[i+1]=ans[i-1];
		} else {
		    ans[i+1]=1-ans[i-1];
		}
		
		if (ans[i] == 0) {
		    //wolf: flip
		    ans[i+1]=1-ans[i+1];
		}
	    }

	    
	    for (int i=0; i<n; i++) {
		int nxt=(i+1)%n;
		int prv=(i-1+n)%n;
		if (ans[prv] == ans[nxt]) {
		    if (ans[i] == 1) {
			if (s[i]=='x') ok=false;
		    } else {
			if (s[i]=='o') ok=false;
		    }
		} else {
		    if (ans[i] == 1) {
			if (s[i]=='o') ok=false;
		    } else {
			if (s[i]=='x') ok=false;
		    }
		}
	    }
	    
	    
	    if (ok) {
		print_ans(ans);
		return 0;
	    }
	}
    }

    cout<<-1<<endl;
  

    return 0;
}
