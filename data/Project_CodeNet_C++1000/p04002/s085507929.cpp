#include <bits/stdc++.h>
#define R(i,a,n) for(int i=a;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef pair<int,int>P;


int dx[]={-2,-1,0,-2,-1,0,-2,-1,0};
int dy[]={-2,-2,-2,-1,-1,-1,0,0,0};

map<pair<int,int>,bool>m;
set<pair<int,int> >st;
int cnt;

int y[100009],x[100009],n,h,w;

signed main(){
	cin>>h>>w>>n;
	rep(i,n){
		cin>>y[i]>>x[i];
		y[i]--;x[i]--;
		m[P(y[i],x[i])]=true;
	}
	int a[10]={};
	rep(i,n){
		rep(j,9){
			int sum=0;
			int yy=y[i]+dy[j];
			int xx=x[i]+dx[j];
			if(yy<0||xx<0||yy+2>=h||xx+2>=w)continue;
			if(st.count(P(yy,xx)))continue;
			rep(k,9){
				int ny=yy+(dy[k]*-1);
				int nx=xx+(dx[k]*-1);
				if(m[P(ny,nx)])sum++;
			}
			//cout<<yy<<' '
			st.insert(P(yy,xx));
			a[sum]++;
			cnt++;
		}
	}
	cout<<(long long)a[0]+(long long)(h-2)*(w-2)-cnt<<endl;
	rep(i,9)cout<<a[i+1]<<endl;
}