#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;
#define pprint(A,y,m,n) rep(J,0,m){print(A[J],y,n);}
const long mod=1e9+7;
const int size=1e5+1;
const int inf=1e9+1;
int main(){
	int N; cin>>N;
	int c[N]; int p;
	rep(i,0,N){ cin>>p; c[p-1] = i - N + inf; }
	int a[N],b[N]; a[0] = 1; b[0] = c[0] - 1;
	rep(i,1,N){
		if(c[i-1] < c[i]){
            b[i] = b[i-1] - 1;
            a[i] = c[i] - b[i];
        }else{
            a[i] = a[i-1] + 1;
            b[i] = c[i] - a[i];
        }
	}print(a,,N);print(b,,N);
}