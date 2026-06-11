#include <iostream>
using namespace std;
long long dist(long long a, long long b, long long c, long long d){
	return abs(a-c)+abs(b-d);
}

int main() {
	int N, M;
	cin >> N >> M;
	long long s[N][2];
	long long p[M][2];
	for (int i=0; i<N; i++){
		cin >> s[i][0] >> s[i][1];
	}
	for (int i=0; i<M; i++){
		cin >> p[i][0] >> p[i][1];
	}
	
	for (int i=0; i<N; i++){
		long long x = dist(s[i][0],s[i][1],p[0][0],p[0][1]);
		int order = 1;
		for (int j=1; j<M; j++){
			long long y = dist(s[i][0],s[i][1],p[j][0],p[j][1]);
			if (y<x){ 
				x = y;
				order = j+1;
			}
		}
		cout << order << '\n';
	}
}