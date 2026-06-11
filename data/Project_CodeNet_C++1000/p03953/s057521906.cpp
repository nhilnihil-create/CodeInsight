#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int N, M;
ll K;
ll x[100000];
ll d[100000];
int a[100000];

vector<int> manip;

void init(){
    for(int i = 0; i < N; i++) manip.push_back(i);
}

/**
 * 置換操作 
 */
vector<int> replace(vector<int> prev, vector<int> operation){
    int n = operation.size();
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        ans[i] = prev[operation[i]];
    }
    return ans;
}

vector<int> pow(vector<int> a, ll n) {
	vector<int> ans;
    for(int i = 0; i < a.size(); i++) ans.push_back(i);
	vector<int> tmp = a;
	for (int i = 0; i <= 60; i++) {
		ll m = (ll)1 << i;
		if (m & n) {
		ans = replace(ans, tmp);
		}
		tmp = replace(tmp, tmp);
	}
	return ans;
}

ll ans[100000];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> x[i];
    for(int i = 0; i < N-1; i++) d[i] = x[i+1]-x[i];
    cin >> M >> K;
    for(int i = 0; i < M; i++) {
        cin >> a[i];
        a[i]-=2;
    }
    init();
    for(int i = 0; i < M; i++){
        swap(manip[a[i]], manip[a[i]+1]);
    }
    vector<int> last = pow(manip, K);
    ans[0] = x[0];
    for(int i = 0; i < N-1; i++){
        ans[i+1] = ans[i]+d[last[i]];
    }
    for(int i = 0; i < N; i++) cout << ans[i] << endl;
}