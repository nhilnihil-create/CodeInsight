#include <iostream>
#include <vector>
using namespace std;
int x[110];
vector<int> v,a,b;
int main(){
	int i,n,m,j;
	cin >> n >> m;
	for(i=0;i<m;i++){
		cin >> x[i];
		if(x[i]&1){
			v.push_back(x[i]);
		}
	}
	if(v.size()>2){
		cout << "Impossible" << endl;
		return 0;
	}
	if(v.size()){
		a.push_back(v.back());
		v.pop_back();
	}
	for(i=0;i<m;i++){
		if(!(x[i]&1)) a.push_back(x[i]);
	}
	if(v.size()){
		a.push_back(v[0]);
	}
	for(i=0;i<m;i++){
		cout << a[i] << " ";
	}
	cout << endl;
	if(m==1){
		if(n==1){
			cout << 1 << endl;
			cout << 1 << endl;
		}else{
			cout << 2 << endl;
			cout << 1 << " " << n - 1 << endl;
		}
		return 0;
	}
	b.push_back(a[0] + 1);
	for(i=1;i<m-1;i++){
		b.push_back(a[i]);
	}
	if(a[m - 1]!=1) b.push_back(a[m - 1] - 1);
	cout << b.size() << endl;
	for(i=0;i<b.size();i++){
		cout << b[i] << " ";
	}
	cout << endl;
}
