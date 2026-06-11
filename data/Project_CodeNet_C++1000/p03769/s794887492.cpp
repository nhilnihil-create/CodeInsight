#include <iostream>
#include <vector>
#define LL long long
using namespace std;

#define VI vector<int>
LL N;

pair<VI ,VI> get_ans(LL N, int mval){
	vector<int> l,r; 
	l.clear(),r.clear();
	if (N!=0){
		int nval=mval-1;
		if (N%2==0) nval--;
		pair<VI,VI> res = get_ans((N-1)/2,nval);
		
		l=res.first,r=res.second;
		l.insert(l.begin(),mval);
		r.insert(r.begin(),mval);
		if (N%2==0) l.insert(l.begin(),mval-1),r.push_back(mval-1);
	}
	
	
	return make_pair(l,r);
}

int main(){
	cin >> N;
	
	pair<VI,VI> ans = get_ans(N,100);
	cout << ans.first.size()+ans.second.size() << "\n";
	for (int x : ans.first)
		cout << x << " ";
		
	for (int x : ans.second)
		cout << x << " ";
	cout << "\n";
	return 0;
}
