#include <iostream>
//#include <iomanip>
//#include <string>
#include <algorithm>
//#include <utility>
//#include <stack>
//#include <queue>
//#include <tuple>
//#include <set>
//#include <map>
//#include <unordered_map>
//#include <vector>
//#include <functional>
#include <bitset>
//#include <cmath>
using namespace std;

typedef long long lint;
typedef unsigned long long ulint;
#define MOD 1000000007

int main(){
    bitset<5001> B;
    int N,K;
    cin >> N >> K;
    int A[5000];
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    sort(A,A+N);

    int l=-1,u=N;
    while(u-l>1){
        int i=(l+u)/2;
        B=1;
        for(int j=0;j<N;j++){
            if(j!=i) B|=(B<<A[j]);
        }
        for(int j=K-1;j>=K-A[i];j--){
            if(j<0) break;
            if(B[j]){
                u=i;
                break;
            }
        }
        if(u!=i) l=i;
    }

    cout << (l+1) << endl;

    return 0;
}