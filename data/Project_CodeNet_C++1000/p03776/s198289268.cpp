#include <bits/stdc++.h>

using namespace std;

const int MAX_C = 60;
long long Com[MAX_C][MAX_C];

void calc_com() {
    memset(Com, 0, sizeof(Com));
    Com[0][0] = 1;
    for (int i = 1; i < MAX_C; ++i) {
        Com[i][0] = 1;
        for (int j = 1; j < MAX_C; ++j) {
            Com[i][j] = Com[i-1][j-1] + Com[i-1][j];
        }
    }
}

int main() {
	calc_com();
	int N,A,B; cin >> N >> A >> B;
	vector<long long> v(N);
	for(auto&a:v) cin >> a;
	sort(v.begin(),v.end(),greater<>());
	auto a=lower_bound(v.begin(),v.end(),v[A-1],greater<>());
	auto b=upper_bound(v.begin(),v.end(),v[A-1],greater<>());
	int cnt=distance(a,b);
	double res=0;
	for(int i=0;i<A;++i) res+=v[i];
	res/=A;
	printf("%.10f\n",res);
	if(v[0]==v[A-1]) {
		long long ans=0;
		for(int i=A;i<=min(B,cnt);++i) ans+=Com[cnt][i];
		cout << ans << endl;
	} else cout << Com[cnt][A-(a-v.begin())] << endl;
	
	return 0;
}