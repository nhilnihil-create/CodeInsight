#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
        A.at(i)--;
    }
    int cnt = 0, temp = 0; 
    for(;;){
        if(temp == 1){
            cout << cnt << endl;
            break;
        }
        if(cnt >= N){
            cout << -1 << endl;
            break;
        }
        cnt++;
        temp = A.at(temp);
    }
    return 0;
}