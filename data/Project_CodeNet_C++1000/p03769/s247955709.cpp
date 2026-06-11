#include <iostream>
#include <vector>
#define llint long long

using namespace std;

llint n;
vector<int> vec, vec2;

int main(void)
{
	cin >> n;
	n++;
	
	int keta = 0;
	for(llint t = n; t; t/=2) keta++;
	
	int id = 1;
	for(int i = keta-2; i >= 0; i--){
		vec.push_back(id), vec2.push_back(id++);
		if(n & (1LL<<i)) vec.insert(vec.begin(), id), vec2.push_back(id++);
	}
	cout << vec.size()*2 << endl;
	for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
	for(int i = 0; i < vec2.size(); i++) cout << vec2[i] << " ";
	
	return 0;
}