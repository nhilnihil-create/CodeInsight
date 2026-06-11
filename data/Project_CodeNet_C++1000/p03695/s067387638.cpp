#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The value of " << #val << " is = " << val << '\n';
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
const ll mininf = -922337203685477;
const ll nax = 0;
unordered_map<int, int>color;
int sabeb=0;

int main(){
	IOS
	int n;
	cin >> n;
	while(n--){
		int x;
		cin >> x;
		if(x<400) color[1]=1;
		else if(x<800) color[2]=1;
		else if(x<1200) color[3]=1;
		else if(x<1600) color[4]=1;
		else if(x<2000) color[5]=1;
		else if(x<2400) color[6]=1;
		else if(x<2800) color[7]=1;
		else if(x<3200) color[8]=1;
		else sabeb++;
	}
	int mins=0;
	for(int i=1;i<=8;i++){
		mins+=color[i];
	}
	cout << max(mins, 1) << ' ' << mins+sabeb << '\n';
}
