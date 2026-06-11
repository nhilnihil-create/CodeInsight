#include<bits/stdc++.h>
using namespace std;

#define PII pair < int , int >
const int _ = 3e5 + 7;
int sum[_] , N , M; PII segt[_];
namespace BIT{
#define lowbit(x) (x & -x)
	int arr[_];
	void add(int x , int val){while(x <= M){arr[x] += val; x += lowbit(x);}}
	int qry(int x){int sum = 0; while(x){sum += arr[x]; x -= lowbit(x);} return sum;}
}using namespace BIT;

int main(){
	ios::sync_with_stdio(0); cin >> N >> M;
	for(int i = 1 ; i <= N ; ++i) cin >> segt[i].first >> segt[i].second;
	sort(segt + 1 , segt + N + 1); int pos = 1; priority_queue < PII > q;
	for(int i = 1 ; i <= M ; ++i){
		while(!q.empty() && q.top().first == -i){add(q.top().second , -1); q.pop();}
		while(pos <= N && segt[pos].first == i){add(i , 1); q.push(PII(-segt[pos++].second - 1 , i));}
		for(int j = 1 ; j * j <= i ; ++j)
			if(!(i % j)){sum[j] += qry(i) - qry(i - j); if(j != i / j) sum[i / j] += qry(i) - qry(i - i / j);}
	}
	for(int i = 1 ; i <= M ; ++i) cout << sum[i] << endl;
	return 0;
}