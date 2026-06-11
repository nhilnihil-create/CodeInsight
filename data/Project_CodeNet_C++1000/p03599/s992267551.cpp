#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int A,B,C,D,E,F; cin>>A>>B>>C>>D>>E>>F;
	vector<bool> water(F+1,false), sugar(F+1,false);
	for (int i=0; 100*i*A<=F; i++)
		for (int j=0; 100*(i*A+j*B)<=F; j++)
			water[100*(i*A+j*B)]=true;
	for (int i=0; i*C<=F; i++)
		for (int j=0; i*C+j*D<=F; j++)
			sugar[i*C+j*D]=true;
	int x=-1, y=-1;
	for (int i=1; i<=F; i++) {
		for (int j=0; i+j<=F; j++) {
			if(!water[i]) continue;
			if(!sugar[j]) continue;
			if(j*100>i*E) continue;
			int xx=i+j, yy=j;
			if(x==-1&&y==-1)
				x=xx, y=yy;
			else {
				if(x*yy>=y*xx)
					x=xx, y=yy;
			}
		}
	}
	cout<<x<<" "<<y<<"\n";
	return 0;
}