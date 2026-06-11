//g++ -std=c++14 test.cpp -o test.out

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL H,W;
char A[100][100];

string ans = "No";
 
void solve(){
	vector<int> alpha(26,0);//文字cが、Aに何個含まれるかをalpha[c]とおく
	for(int h=0;h<H;h++){
    	for(int w=0;w<W;w++){
    		alpha[A[h][w]-'a']++;
    	}
    }

    vector<int> num(4,0);//alphaのうち、4で割った余りがiのものが何個あるかをnum[i]とおく
    for(int i=0;i<26;i++){
    	num[alpha[i]%4]++;
    }

    if (H%2==1 && W%2==1) {
        if (num[3]) {
            num[3]--;
            num[1]++;
            num[2]++;
        }
        if (num[3]) return;
        if (num[1] == 1 && num[2] <= (H/2+W/2)) ans = "Yes";
        else return;
    } else if (H%2==1) {
        if (num[3] || num[1]) return;
        if (num[2] <= W/2) ans = "Yes";
        else return;
    } else if (W%2==1) {
        if (num[3] || num[1]) return;
        if (num[2] <= H/2) ans = "Yes";
        else return;
    } else {
        if (num[1] || num[2] || num[3]) return;
        else ans = "Yes";
    }
}
 
int main(){
    cin >> H >> W;
    for(int h=0;h<H;h++){
    	for(int w=0;w<W;w++) cin >> A[h][w];
    }
 
    solve();
 
    cout << ans << endl;
    return 0;
}