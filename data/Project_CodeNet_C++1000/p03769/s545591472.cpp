#include<iostream>
#include<deque>
using namespace std;
typedef long long LL;
LL N;
int tot=0;
deque <int> le,re;
inline void solve(LL n){
	if(n==1)
		return;
	solve(n>>1);
	le.push_front(++tot);
	re.push_front(tot);
	if(n&1){
		le.push_front(++tot);
		re.push_back(tot);
	}
}

int main(){
	cin>>N;
	solve(N+1);
	cout<<le.size()+re.size()<<endl;
	for(int i=0;i<le.size();i++)
		cout<<le[i]<<" ";
	for(int i=0;i<re.size();i++)
		cout<<re[i]<<" ";
	cout<<endl;
	return 0;
} 