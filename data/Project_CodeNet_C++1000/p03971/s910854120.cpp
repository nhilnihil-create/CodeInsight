#include <bits/stdc++.h>

using namespace std;

int main() {
	int n,a,b;
    string s;
    cin>>n>>a>>b>>s;

    int currentlyPassed = 0;
    int overseasSoFar = 0;

    for(int i=0; i<n; i++) {
        if(s[i] == 'a') {
            int cond = currentlyPassed < (a+b);
            currentlyPassed += cond;
            if(cond) cout<<"Yes\n";
            else cout<<"No\n";
        }
        else if(s[i] == 'b') {
            int cond = currentlyPassed < (a+b) && overseasSoFar < b;
            currentlyPassed += cond;
            overseasSoFar++;
            if(cond) cout<<"Yes\n";
            else cout<<"No\n";
        }
        else cout<<"No\n";
    }
	
	return 0;
}