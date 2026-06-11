#include <iostream>
using namespace std;

int main() {
	int N, P;
	bool same[100010];
	cin >> N;
	for(int i=1; i<=N; ++i){
	    cin >> P;
	    same[i]=(P==i);
	}
	int ans=0;
	for(int i=1; i<N; ++i){
	    if(same[i]){
	        ++ans;
	        if(same[i+1]) same[i+1]=false;
	    }
	}
	if(same[N]) ++ans;
	cout << ans << endl;
	return 0;
}
