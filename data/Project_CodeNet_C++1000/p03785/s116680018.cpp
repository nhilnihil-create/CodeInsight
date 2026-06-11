#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, c, k;
	cin >> n >> c >> k;
	vector<int> t(n);
	for(auto& x: t){
		cin >> x;
	}
	sort(t.begin(), t.end());
	t.push_back(0);
	int count_time = 0;
	int count_bus = 0;
	int count_people = 0;
	bool begin_flag = 1;
	for(int i = 0;i < n; i++){
		if(begin_flag == 0){
			count_time += t.at(i) - t.at(i-1);
			count_people++;
		}
		if(begin_flag == 1){
			count_people++;
			begin_flag = 0;
		}
		if(count_time > k || count_people > c){
			count_bus++;
			count_time = 0;
			count_people = 0;
			begin_flag = 1;
			i--;
		}
	}
	cout << count_bus+1 << endl;
}
