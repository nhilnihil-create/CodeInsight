#include <bits/stdc++.h>
using namespace std;


int main() {

	int64_t n;
	cin >> n;


    uint64_t minimum = 100;
    vector<int64_t> divisor;
    for(int64_t i=1;i*i<=n;i++){
        if(n%i==0){
            string wk1,wk2;
            wk1 = to_string(i);
            wk2 = to_string(n/i);
            minimum = min(max((uint64_t)wk1.size(),(uint64_t)wk2.size()),minimum);
        }
    }

    cout<<minimum<<endl;

	return 0;
}