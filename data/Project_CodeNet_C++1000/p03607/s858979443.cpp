#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#include <limits>
#include <iomanip>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    int cnt=0;
    int num=0;
    for(int i=0;i<N;i++){
        if(i!=0){
            if(A[i-1]!=A[i]){
                if(num%2==1){
                    cnt++;
                    num=1;
                }
                else{
                    num=1;
                }
            }
            else{
                num++;
            }
        }
        else{
            num=1;
        }
    }
    if(num%2==1){
        cnt++;
    }
    cout<< cnt<< endl;

}