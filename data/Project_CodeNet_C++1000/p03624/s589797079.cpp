#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    string s;
    cin>>s;
    vector<long long> a(26,0);
    f(i,0,s.size()){
        a[s[i]-'a']++;
    }
    f(i,0,26) {
		if (a[i] == 0) {
		    
			cout << (char)(i + 'a') << endl;
			return 0;
		}
	}
	cout << "None" << endl;
    return 0;
}
