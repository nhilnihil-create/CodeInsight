#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <cstring>
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <numeric>
#include <float.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef unsigned long long ll;

int main(){
int N; cin >> N;
vector<int> A(N);
rep(i,N) cin >> A[i];
int cnt = 0;
rep(i,N){
	if(A[i] == A[i+1]){
		continue;
	}
	else if(A[i] > A[i+1]){
		while(A[i] >= A[i+1]){
			i++;
		}
		cnt++;
	}
	else{
		while(A[i] <= A[i+1]){
			i++;
		}
		cnt++;
	}
}
cout << cnt << endl;
}