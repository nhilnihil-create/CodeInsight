
#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first
#define b second
int n,l;
int it[100001];
vector<int> aa[100001];
int par[100001];
int co[100001];
int ne[100001][20];
int ne2[100001][20];
int bb,cc;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>it[i];
		ne[i][0]=-1;
		ne2[i][0]=-1;
	}
	int j=0;
	cin>>l;
	for(int i=0;i<n-1;i++){
		while(j<n-1){

			if(it[j+1]-it[i]<=l){
				j+=1;
			}
			else{
				break;
			}
		}
		ne[i][0]=j;
	}
	j=n-1;
	for(int i=n-1;i>0;i--){
		while(j>0){
			if(it[i]-it[j-1]<=l){
				j-=1;
			}
			else{
				break;
			}
		}
		ne2[i][0]=j;
	}
	for(int j=1;j<20;j++){
		for(int i=0;i<n;i++){
			if(ne[i][j-1]==-1){
				ne[i][j]=-1;
			}
			else{
				ne[i][j]=ne[ne[i][j-1]][j-1];
			}
		}
	}
	for(int j=1;j<20;j++){
		for(int i=0;i<n;i++){
			if(ne2[i][j-1]==-1){
				ne2[i][j]=-1;
			}
			else{
				ne2[i][j]=ne2[ne2[i][j-1]][j-1];
			}
		}
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>bb>>cc;
		bb--;
		cc--;
		if(bb<cc){
			int tot=0;
			for(int j=19;j>=0;j--){
				if(ne[bb][j]==-1){
					continue;
				}
				if(ne[bb][j]<cc){
					bb=ne[bb][j];
					tot+=(1<<j);
				}
			}
			cout<<tot+1<<endl;
		}
		else{
			int tot=0;
			for(int j=19;j>=0;j--){
				if(ne2[bb][j]==-1){
					continue;
				}

				if(ne2[bb][j]>cc){
					bb=ne2[bb][j];
					tot+=(1<<j);
				}
			}
			cout<<tot+1<<endl;
		}
	}

	return 0;
}
