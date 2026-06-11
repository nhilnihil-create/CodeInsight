#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N,0);
    long long sum_=0;
    long long amount=0;
    for(int i=0; i<N; i++){
        cin >> A[i];
        sum_+=(long long) A[i];
        amount+=(long long)i+1;
    }
    string ans ="YES";
    if(sum_%amount!=0){
        cout << "NO" <<endl;
        return 0;
    }
    long long num = sum_/amount;
    for(int i=0; i<N; i++){
        int diff=A[(i+1)%N]-A[i];
        if(num-diff >= 0 && abs(num-diff)%N==0)continue;
        else{
            ans="NO";
            break;
        }
    }
    cout << ans << endl;
}