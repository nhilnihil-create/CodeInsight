#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;
#define pprint(A,y,m,n) rep(J,0,m){print(A[J],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int main(){
	int N; long A,B,C,D; cin>>N>>A>>B>>C>>D;
    if(C == 0 && D == 0){
        cout<<(A == B ? "YES" : "NO")<<endl;
        return 0;
    }
    long k = abs(A - B);
    long x = (k + D*(N-1)) / (C+D);
    long y = (k + C*(N-1) + (C+D-1)) / (C+D);
    if(y <= x && y < N) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}