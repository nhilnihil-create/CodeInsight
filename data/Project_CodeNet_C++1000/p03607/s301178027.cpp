#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    int t = 1; //cin >> t;
    while(t--){
    	int n; cin >> n;
    	set<int> s;
    	while(n--)
    	{
    		int x; cin >> x;
    		if(s.find(x) == s.end())
    			s.insert(x);
    		else s.erase(x);
    	}
    	cout << s.size();
    }    	
}