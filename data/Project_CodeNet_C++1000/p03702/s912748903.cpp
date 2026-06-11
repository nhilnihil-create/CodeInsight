#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
    LL N, A, B;
    cin >> N >> A >> B;
    vector<LL>  h(N);
    for(int i = 0;i < N;i++)    cin >> h[i];
    LL M = 1e9;
    LL m = 0;
    LL mid;
    while(true){
        mid = (m+M)/2;
        LL count = 0;
        for(int i = 0;i < N;i++){
            LL hi = h[i];
            hi -= B*mid;
            if(hi > 0){
                count += hi/(A-B);
                if(hi%(A-B))    count++;
            }
        }
        if(count > mid) m = mid;
        else    M = mid;
        if(M-m == 1)    break;
    }
    cout << M << endl;
}