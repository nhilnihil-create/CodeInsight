#include <bits/stdc++.h>
#define ll long long
#define INF 999999999
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

typedef pair<int,int>P;

const int MAX_N = 100005;

vector<int> x[MAX_N];
int a[MAX_N]; //いくつあるか
int b[MAX_N]; //vectorごとに値を保持

int main()
{
	int n,m,buff,ans=0;
	cin >> n >> m;
	fill(a,a+n,0);
	fill(b,b+n,0);
	rep(i,n){
		scanf("%d",&buff);
		a[buff]++;
		x[buff%m].push_back(buff); 
	}
	for(int i=1;i<=100000;i++){
		int pair = a[i]/2;
		b[i%m] += pair;
	}
	int hoge;
	ans+=x[0].size()/2;
	if(m%2==0){
		ans += x[m/2].size()/2;
		for(int i=1;i<m/2;i++){
			if(x[i].size()>x[m-i].size()){
				hoge = x[i].size()-x[m-i].size();
				ans += (x[m-i].size() + min(hoge/2,b[i]));
			}else if(x[i].size()==x[m-i].size()){
				ans += x[i].size();
			}else{
				hoge = x[m-i].size()-x[i].size();
				ans += (x[i].size() + min(hoge/2,b[m-i]));
			}
		}
	}else{
		for(int i=1;i<=(m-1)/2;i++){
			if(x[i].size()>x[m-i].size()){
				hoge = x[i].size()-x[m-i].size();
				ans += (x[m-i].size() + min(hoge/2,b[i]));
			}else if(x[i].size()==x[m-i].size()){
				ans += x[i].size();
			}else{
				hoge = x[m-i].size()-x[i].size();
				ans += (x[i].size() + min(hoge/2,b[m-i]));
			}
		}
	}
	cout << ans << "\n";
}