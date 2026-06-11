#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

long long MOD = 1000000007;

int main(){
    int N;
    cin >> N;
    
    int max_=0;
    int min_=MOD;
    vector<int> A(N,0);

    for(int i=0; i<N; i++){
        int a;
        cin >> a;

        max_=max(max_, a);
        min_=min(min_, a);
        A[a]++;
    }

    //cout << N << ' ' << max_ << ' ' << min_ << endl;
    if(max_-min_>1){
        cout << "No" << endl;
        return 0;
    }else if(max_-min_==0 && min_==N-1){
        cout << "Yes" << endl;
        return 0;
    }

    if(max_-N+A[max_]>0 && A[max_]/(max_-N+A[max_])>=2){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}