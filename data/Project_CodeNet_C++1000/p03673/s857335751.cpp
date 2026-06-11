#include <iostream>
#include <vector>
#include <deque>
#include <list>
using namespace std;
int main(){
	int n;
	cin >> n;
	deque<int>deq;
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
			deq.push_back(tmp);
		}else{
			deq.push_front(tmp);
		}
        if(f) f=0;
        else f=1;
	}
    for(auto itr = deq.begin(); itr !=deq.end(); ++itr){
        cout << deq.front() << " ";
        deq.pop_front();
    }
	cout << endl;
    return 0;
}