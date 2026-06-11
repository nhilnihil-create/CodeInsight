#include <bits/stdc++.h>

#ifdef NON_SUBMIT
#define TEST(n) (n)
#define tout cerr
#else
#define TEST(n) ((void)0)
#define tout cin
#endif

using namespace std;

vector<int> A(1);
int D[5001][5001];
bool D2[5001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	TEST(freopen("input.txt","r",stdin));
	TEST(freopen("output.txt","w",stdout));
	TEST(freopen("debug.txt","w",stderr));
	int N, K, ans=0;
	cin>>N>>K;
	for(int i=0;i<N;i++) {
		int a;
		cin>>a;
		if(a<K) A.push_back(a);
	}
	ans=N=A.size(); ans--;
	D[0][0]=D2[0]=1;
	for(int i=1;i<N;i++) {
		for(int j=K;j>=0;j--) {
			D[i][j]=D[i-1][j];
			if(j>=A[i] && D[i-1][j-A[i]]) D[i][j]=1;
		}
	}
	for(int i=N-1;i>0;i--) {
		for(int j=1;j<=K;j++) D[i-1][j]+=D[i-1][j-1];
		for(int j=0;j<K;j++) if(D2[j] && D[i-1][K-1-j]>(K-1-A[i]-j>=0 ? D[i-1][K-1-A[i]-j]:0)) {
			ans--;
			break;
		}
		for(int j=K-A[i];j>=0;j--) D2[j+A[i]]|=D2[j];
	}
	cout<<ans<<'\n';
	return 0;
}