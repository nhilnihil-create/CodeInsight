#include <iostream>
using namespace std;

int main0() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
	int N, K;
	cin >> N >> K;
	long long arr[100001]={};
	int num, qty;
	long long count = 0;
	for (long long i=0; i<N; i++){
		cin >> num >> qty;
		arr[num]+=qty;
	}
	for (int i=1; i<100001; i++){
		count += arr[i];
		if (count >= K){
			cout << i << endl;
			return 0;
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n , k;
    cin >> n >> k;
    long long arr[100001] = {};
    for (long long i = 0 ; i < n ; i++){
        int num , qty;
        cin >> num >> qty;
        arr[num] += qty;
    }
    long long count = 0;
    for (long long i = 1 ; i < 100001 ; i++ ){
       count += arr[i];
       if( count >= k ){
         cout << i;
         return 0;
       }
    }
}

