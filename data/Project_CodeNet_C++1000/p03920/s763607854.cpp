#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

/****************** B **********************/
int main()
{
	int N = 0;
	cin >> N;
	int up_to_this = 0;
	for(int i = 1; i <= N; i++){
		if(i * (i + 1) / 2 >= N){
			up_to_this = i;
			break;
		}
	}
	int dif = up_to_this * (up_to_this + 1) / 2 - N;
	vector<int> ans;
	for(int i = 1; i <= up_to_this; i++){
		if(i != dif) ans.push_back(i);
	}
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << endl;
	}

	return 0;
}