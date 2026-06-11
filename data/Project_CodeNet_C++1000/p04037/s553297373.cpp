#include<bits/stdc++.h>
#define rint register int 
#define ll long long 
using namespace std;
int N,A[1010000];
inline bool cmp(int i,int j){return i>j;}
int main() {
	cin>>N;
	for(rint i=1;i<=N;++i) cin>>A[i];
	sort(A+1,A+N+1,cmp);
	int pos=0;
	for(rint i=1;i<=N+1;++i){
		if(A[i]<i) {
			pos=i-1;
			int x=A[pos]-pos;
			int y=0;
//			cout<<pos<<endl;
			for(rint x=pos+1;x<=N;++x) if(A[x]>=pos) ++y;
			if((x&1)||(y&1)) {
				cout<<"First\n";
			}
			else cout<<"Second\n";
			exit(0);
		}
	}
	return 0;
}