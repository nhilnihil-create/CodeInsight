#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;
#define pprint(A,y,m,n) rep(J,0,m){print(A[J],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int main(){
	int H,W,h,w; cin>>H>>W>>h>>w;
	if(H % h == 0 && W % w == 0) cout<<"No"<<endl;
	else{
		int a[H][W] = {};
		int s,t;
        if(h == 1){ s = W / w + 1; t = - s * (w - 1) - 1; }
        else if(w == 1){ s = H / h + 1; t = - s * (h - 1) - 1; }
        else{ s = (H / h) * (W / w) / min(H, W) + 1; t = - s * (h + w - 1) - 1; }
		for(int i = 0; i < H; i += h){
			rep(j,0,W) a[i][j] = s;
		}for(int j = 0; j < W; j += w){
            rep(i,0,H) a[i][j] = s;
        }
		for(int i = h-1; i < H; i += h){
			for(int j = w-1; j < W; j += w){
				a[i][j] = t;
			}
		}
		cout<<"Yes"<<endl;
		pprint(a,,H,W);
	}
}