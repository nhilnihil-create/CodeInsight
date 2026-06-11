#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <cmath>
#include <map>
using namespace std;

int N;
vector <int> kekka;
bool vld[10101010];

int main()
{
	cin >> N;
	int sum=0;
	for(int i=1; i<N+1; i++){
		sum += i;
		kekka.push_back(i);
		if(sum==0){
			break;
		}
		else if(sum>N){
			kekka.erase(remove(kekka.begin(), kekka.end(), sum-N), kekka.end());
			break;
		}
	}
	for(int i=0; i<kekka.size(); i++){
		cout << kekka[i] << endl;
	}
	return 0;
}
