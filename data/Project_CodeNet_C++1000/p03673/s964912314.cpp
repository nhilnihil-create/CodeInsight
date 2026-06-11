#include <iostream>
#include <vector>
#include <list>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int>a(n);
	list<int>b;
	bool f = true;
	if(n%2 == 0){
		f = true;
	}else{
		f = false;
	}
	for(int i=0; i<n; ++i){
		int tmp;
		cin >> tmp;
		if(f){
			b.push_back(tmp);
		}else{
			b.push_front(tmp);
		}
        if(f) f=0;
        else f=1;
	}

	for(auto x : b){
		cout << x << " ";
	}

	cout << endl;
    return 0;
}