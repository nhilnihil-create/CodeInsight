#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define pb push_back

int main(){
	int n;
	cin>>n;
	forsn(i, 1, n+1){
		int ot=n;
		vector<int> v;
		forn(j, i){
			int hago=i-j;
			if (hago<=ot){
				v.pb(hago);
				ot-=hago;
			}
		}
		if(ot==0){
			forn(si, v.size()){
				cout<<v[si]<<endl;
			}
			return 0;
		}
	}
}
