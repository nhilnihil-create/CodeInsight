#include<iostream>
#include<algorithm>
using namespace std;

int Time[100005];

int main(){
    int N, C, K, ans = 0;
    cin >> N >> C >> K;
    for(int i=1; i<=N; i++){
        cin >> Time[i] ;
    }
    sort(Time + 1, Time + N + 1);
    for(int i=1; i<=N; i++){
        ans++;
        int temp = i;
        for(int j=temp+1; j<=temp+C-1; j++){
            if(j > N) break;
            if(Time[j] <= Time[temp]+K){
                i++;
            }
        }
    }
    cout << ans << endl;
}