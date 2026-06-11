#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
//通过999...9和1000...0确定N的位数
//通过二分答案(比N多一位)确定N的大小 
bool smaller_than_N(int n){
	cout<<"? "<<n<<"0\n"<<flush;
	char c;cin>>c;
	return c=='N';
}
int main(){
	int t=1;
	//N!=10^m
	rep1(w,9){
		char c1,c2;
		cout<<"? ";rep(k,w)cout<<'9';cout<<'\n'<<flush;cin>>c1;
		cout<<"? 1";rep(k,w)cout<<'0';cout<<'\n'<<flush;cin>>c2;
		if(c1=='Y'&&c2=='N'){
			int l=t,r=t*10-1;
			while(l<r){
				int mid=(l+r)>>1;
				if(smaller_than_N(mid))l=mid+1;
				else r=mid;
			}
			cout<<"! "<<r<<'\n'<<flush;
			return 0;
		}
		t*=10;
	}
	//N=10^m
	rep1(w,10){
		cout<<"? ";rep(k,w)cout<<'2';cout<<'\n'<<flush;
		char c;cin>>c;
		if(c=='Y'){
			cout<<"! 1";rep(k,w-1)cout<<'0';cout<<'\n'<<flush;
			return 0;
		}
	}
	return 0;
}