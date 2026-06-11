#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;


int solve(int i, int j, int d){
	i %= (d * 2);
	j %= (d * 2);
	int ret = 0;
	if(i >= d) i -= d, ret ^= 1;
	if(j >= d) j -= d, ret ^= 1;
	if(i + j < d / 2 - 1 || i + j >= d * 3 / 2 - 1) ret ^= 0;
	else if(j - i > d / 2 || i - j >= d / 2) ret ^= 1;
	else ret ^= 2;
	return ret;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int h, w, d;
    cin >> h >> w >> d;
    string t = "RYGB";
    string s;
    if(d & 1){
    	for(int i=0;i<h;i++){
    		s = "";
    		for(int j=0;j<w;j++){
    			s += t[(i & 1) * 2 + (j & 1)];
    		}
    		cout << s << endl;
    	}
    	return 0;
    }
    for(int i=0;i<h;i++){
    	s = "";
    	for(int j=0;j<w;j++){
    		s += t[solve(i, j, d)];
    	}
    	cout << s << endl;
    }
    return 0;
}
