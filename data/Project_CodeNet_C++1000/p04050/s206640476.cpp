#include <iostream>
#include <vector>

using namespace std;

int N, M;
int A[100005];
vector<int> odd, even;
vector<int> ans;

int main(void)
{
	cin >> N >> M;
	for(int i = 0; i < M; i++) cin >> A[i];
	
	if(M == 1){
		if(A[0] > 1) ans.push_back(A[0]-1);
		ans.push_back(1);
		
		cout << A[0] << endl;
		cout << ans.size() << endl;
		for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
		return 0;
	}
	
	for(int i = 0; i < M; i++){
		if(A[i] % 2) odd.push_back(A[i]);
		else even.push_back(A[i]);
	}
	
	if(odd.size() >= 3){
		cout << "Impossible" << endl;
		return 0;
	}
	
	if(odd.size() >= 1) even.insert(even.begin(), odd[0]);
	if(odd.size() >= 2) even.push_back(odd[1]);
	
	for(int i = 0; i < even.size(); i++) cout << even[i] << " "; cout << endl;
	
	ans.push_back(even[0]+1);
	for(int i = 1; i < even.size()-1; i++){
		ans.push_back(even[i]);
	}
	if(even.back() > 1) ans.push_back(even.back()-1);
	
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
	
	return 0;
}