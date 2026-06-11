#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> v(N, vector<int>(M, 0)), loc(N, vector<int>(M+1, 0));
	vector<vector<bool>> s(N, vector<bool>(M, 0));
	for(int i=0; i<N; ++i){
	    for(int j=0; j<M; ++j){
	        cin >> v[i][j];
	        loc[i][v[i][j]]=j;
	    }
	}
	int ans=N;
	for(int i=0; i<M; ++i){
	    vector<int> cnt(M+1, 0);
	    for(int j=0; j<N; ++j){
	        int a=0;
	        while(s[j][a]) ++a;
	        ++cnt[v[j][a]];
	    }
	    int mx=0;
	    for(int j=1; j<=M; ++j){
	        if(cnt[mx]<cnt[j]) mx=j;
	    }
	    ans=min(ans, cnt[mx]);
	    for(int j=0; j<N; ++j) s[j][loc[j][mx]]=1;
	}
	cout << ans << endl;
	return 0;
}
