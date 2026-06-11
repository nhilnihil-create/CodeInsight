#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int N = 1e5;

int n,t;
int li[N+5];

int suf[N+5];
int pref[N+5];
priority_queue<int> pq;

map<int,int> pas;

int main(){
	scanf("%d%d",&n,&t); t/=2;
	for(int i=1;i<=n;i++){
		scanf("%d",&li[i]);
	}
	suf[n] = li[n];
	pref[1] = li[1];
	for(int i=n-1;i>=1;i--) suf[i] = max(suf[i+1],li[i]);
	for(int i=2;i<=n;i++) pref[i] = min(pref[i-1],li[i]);
	int tmp = 0;
	for(int i=1;i<n;i++){
		tmp = max(tmp,suf[i+1]-li[i]);
	}
//	cout << tmp << endl;
	for(int i=1;i<n;i++){
		if(suf[i+1]-li[i] == tmp){
//			cout << "COBA " << i << endl;
			pas[li[i]]++;
		}
	}
	for(int i=n;i>1;i--){
		if(li[i] - pref[i-1] == tmp){
			pas[li[i]]++;
		}
	}
	int ans = 0;
	for(int i=1;i<n;i++){
		if(suf[i+1]-li[i] != tmp) continue;
		int cur = pas[li[i]];
		int cur2 = pas[suf[i+1]];
//		cout << cur << " " << cur2 << endl;
		ans += min(cur,cur2);
		pas[li[i]]=0;
		pas[suf[i+1]]=0;
	}
	printf("%d\n",ans);
	return 0;
}
