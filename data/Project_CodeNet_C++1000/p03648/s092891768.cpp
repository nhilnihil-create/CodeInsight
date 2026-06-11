#include <iostream>
//#include <iomanip>
//#include <string>
//#include <algorithm>
//#include <utility>
//#include <stack>
//#include <queue>
//#include <tuple>
//#include <set>
//#include <map>
//#include <unordered_map>
//#include <vector>
//#include <functional>
//#include <bitset>
//#include <cmath>
using namespace std;

typedef long long lint;
typedef unsigned long long ulint;
#define MOD 1000000007

int main(){
    lint K;
    cin >> K;

    cout << 50 << endl;
    lint A[50];
    for(int i=0;i<50;i++) A[i]=50+K/50;
    for(int i=0;i<50-K%50;i++){
        lint max=-1;
        int mi=0;
        for(int j=0;j<50;j++){
            if(max<=A[j]){
                max=A[j];
                mi=j;
            }
        }
        for(int j=0;j<50;j++) A[j]++;
        A[mi]-=51;
    }

    for(int i=0;i<49;i++) cout << A[i] << ' ';
    cout << A[49] << endl;

    return 0;
}