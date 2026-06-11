#include <iostream>

using namespace std;

int main(){
    int N;
    int x[100001];
    int cnt = 0;
    cin >> N;
    for(int i = 1; i <= N; i++){    
        cin >> x[i];
    }
    for(int i = 1; i <= N-1; i++){    
        if(x[i] == i){
            cnt++;
            int tmp = x[i];
            x[i] = x[i+1];
            x[i+1] = tmp;
        } 
    }
    if(x[N] == N) cnt++;
    cout << cnt << endl;
}