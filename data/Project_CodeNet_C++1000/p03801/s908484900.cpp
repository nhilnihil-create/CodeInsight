#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 112345;

int n;
long long v[MAXN];
long long sum = 0LL;
long long ans[MAXN];

map<long long,long long> freq;
stack<pair<long long,long long> > st;

int main(){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	
	st.push(make_pair(0,0));
	
	cin >> n;
	for(int i = 1 ; i <= n ; i ++){
		cin >> v[i];
		freq[v[i]]++;
		sum += v[i];
		if(v[i] > st.top().second)
			st.push(make_pair(i, v[i]));
	}
	
	long long prev = 0LL;
	
	while(st.size() != 1){
		
		int id = st.top().first;
		int x = st.top().second;
		st.pop();
		
		long long middle = 0LL;
		long long cnt = 0LL;
		map<long long,long long> :: iterator it, jt;
		it = freq.lower_bound(st.top().second + 1);
		
		for( ; it != freq.end() ; it++){
          	cnt += it->second;
			if(it->first == x){
              	middle += (it->first - st.top().second) * (prev + it->second);
              	break;
            }
			middle += (it->first - st.top().second) * (it->second);
		}
		
		ans[id] = middle;
		sum -= ans[id];
		if(st.size() == 1) ans[id] += sum;
		prev += cnt;
	}
	
	for(int i = 1 ; i <= n ; i ++)
		cout << ans[i] << "\n";
	
	return 0;
}