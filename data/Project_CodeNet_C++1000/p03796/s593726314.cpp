#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    long long N;
    cin >> N;
    long long val = 1;
    for(int i=1; i<=N; i++){
        val = (val*i)%(1000000000+7);
    }
    cout << val << endl;
    return 0;
}