#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>
#include <random>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> P;


void solve(long long H, long long W, long long d){

}

int main(){
    long long H;
    scanf("%lld",&H);
    long long W;
    scanf("%lld",&W);
    long long d;
    scanf("%lld",&d);
    solve(H, W, d);
	if(d%2==1){
		for(int i=0;i<H;i++){
			for(int j=0;j<W;j++){
				if((i+j)%2){
					cout << "R";
				}
				else{
					cout << "G";
				}
			}
			cout << endl;
		}
		return 0;
	}
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			int x=(i+j)/d;
			int y=(i+W-j)/d;
			if(x%2){
				if(y%2){
					cout << "R";
				}
				else{
					cout << "G";
				}
			}
			else{
				if(y%2){
					cout << "B";
				}
				else{
					cout << "Y";
				}
			}
		}
		cout << endl;
	}
    return 0;
}
