#include <iostream>
using namespace std;

int main() {
	int N; cin >> N;
	int maxx, sum=0;
	for(maxx=1; sum<N; ++maxx) sum += maxx;
	int excu=sum-N;
	for(int i=maxx-1; i>0; --i){
	    if(i!=excu) cout << i << endl;
	}
	return 0;
}
