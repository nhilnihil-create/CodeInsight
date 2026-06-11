#include<bits/stdc++.h>
using namespace std;

int main(){
	long long N; cin >> N; ++N; vector < int > F , T; int cnt = 100;
	while(N != 1) if(N & 1){F.push_back(cnt--); --N;} else{T.push_back(cnt--); N >>= 1;}
	reverse(T.begin() , T.end()); cout << F.size() + T.size() + 100 << endl;
	for(auto t : F) cout << t << ' ';
	for(auto t : T) cout << t << ' ';
	for(int i = 1 ; i <= 100 ; ++i) cout << i << ' ';
	return 0;
}
