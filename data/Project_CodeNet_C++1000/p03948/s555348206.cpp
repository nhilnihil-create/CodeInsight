#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <limits.h>
#include <math.h>

#define repeat(i,n) for (int i = 0; (i) < (n); ++ (i))

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
const ll INF = LONG_LONG_MAX;
const int MAX_P = 55555+1;



int main() {
    // insert code here...    return 0;
    //////
    // input from txt
    /*
     std::ifstream in("input.txt");
     std::cin.rdbuf(in.rdbuf());
     std::ofstream out("output.txt");
     std::cout.rdbuf(out.rdbuf());
     ////
     */
    
    int N,T;
    cin >> N >> T;
    vint A(N);
    repeat(i, N){
        cin >> A[i];
    }
    vint minA(A),profit(N,0);
    int maxprofit=0;
    int cnt=1;
    repeat(i, N-1){
        minA[i+1] = min(minA[i],A[i+1]);
        profit[i+1] = A[i+1] - minA[i+1];
        if(maxprofit<profit[i+1]){
            maxprofit = profit[i+1];
            cnt=1;
        }else if(maxprofit == profit[i+1]){
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}

