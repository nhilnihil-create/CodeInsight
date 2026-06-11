    // "include" {{{
    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <string>
    #include <deque>
    #include <list>
    #include <map>
    #include <queue>
    #include <set>
    #include <stack>
    #include <cstring>
    #include <iomanip>
    #include <tuple>
    // }}}
    using namespace std;
    #define rep(i,n) for(int i=0;i<(n);++i)
    #define reps(i,n) for(int i=1;i<=(n);++i)
    #define all(x) (x).begin(),(x).end()
    #define pii pair<int,int> 
    #define int long long
    #define setout(n,x) setw(n) << setfill(x)
    #define Fixed fixed << setprecision(10)
    const int INF = 0x3f3f3f3f;
    const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
    const long long mod = 1000000007;
     
    signed main(){
    	cin.tie(0);
    	ios::sync_with_stdio(false);
    	string s;
    	cin >> s;
    	int n = s.size();
    	int g = 0,p = 0,sum = 0;
    	rep(i,n){
    		if(s[i] == 'g'){
    			if(g > p){
    				++p;
    				++sum;
    			}
    			else ++g;
    		}
    		else{
    			if(g > p) ++p;
    			else{
    				++g;
    				--sum;
    			}
    		}
    	}
    	cout << sum << '\n';
    	return 0;
    }