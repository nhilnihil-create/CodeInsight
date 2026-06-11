#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

int n;
long long a[100005];
long long gtotal[100005];
long long total;

bool valid(int i){
	int next = (i+1)%n;
	long long tmp = total - a[next] + a[i];
	if(tmp < 0) return false;
	if((tmp % (long long)n) != 0){
		return false;
	} else {
		gtotal[next] =  tmp / (long long)n;
		return true;
	}
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		total += a[i];
	}

	if(n==1){
		cout<<"YES"<<endl;
		return 0;
	}

	long long nn = n;
	if((total % (nn*(nn+1)/2)) != 0){
		cout<<"NO"<<endl;
		return 0;
	}

	total /= (nn*(nn+1)/2);

	for(int i=0;i<n;i++){
		if(valid(i) == false){
			cout<<"NO"<<endl;
			return 0;
		}
	}

	long long tt=0LL;
	for(int i=0;i<n;i++){
		tt += gtotal[i]*(((nn-i)%nn)+1);
	}
	if(tt != a[0]){
		cout<<"NO"<<endl;
		return 0;
	}

	cout<<"YES"<<endl;
	return 0;

}