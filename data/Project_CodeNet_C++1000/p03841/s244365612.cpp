#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;
using namespace std;
pair<int,int> x[510];
int ans[250010];
queue<int> Q;
int main(){
	int n;
	cin>>n;
	lol(i,n*n)ans[i]=-1;
	lol(i,n){
		int a;cin>>a;
		a--;
		ans[a]=i+1;
		x[i]=make_pair(a,i+1);
	}
	sort(x,x+n);
	int pnt=0;
	bool ok=true;
	lol(i,n){
		int lim=x[i].first;
		int t=x[i].second,cnt=x[i].second-1;
		while(cnt){
			if(pnt>=lim){
				ok=false;
				goto loop;
			}
			if(ans[pnt]==-1){
				cnt--;
				ans[pnt]=t;
			}
			pnt++;
		}
	}
	pnt=n*n-1;
	for(int i=n-1;i>=0;i--){
		int lim=x[i].first;
		int t=x[i].second,cnt=n-x[i].second;
		while(cnt){
			if(pnt<=lim){
				ok=false;
				goto loop;
			}
			if(ans[pnt]==-1){
				cnt--;
				ans[pnt]=t;
			}
			pnt--;
		}
	}
	loop:;
	if(ok){
		cout<<"Yes"<<endl;
		lol(i,n*n){
			if(i)cout<<" ";
			cout<<ans[i];
		}
		cout<<endl;
	}
	else cout<<"No"<<endl;
	return 0;
}
