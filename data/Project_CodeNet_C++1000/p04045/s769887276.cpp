#include<iostream>
#include<vector> 
#include<cmath>
#include<algorithm>
#include<functional>
#include<queue>

using namespace std;

int main()
{
    int N, K, x;   cin >> N >> K;
    std::queue<int> que;
    std::vector<int> v(K), u(10-K);
    for(int i=0; i<K; i++)  cin >> v[i];
    int j=0;
    for(int i=0; i<=9; i++){
        if(v[j] == i)   j++;
        else{
            que.push(i);
            u[i-j] = i;
            if(i >= N){
                cout << i;
                return 0;
            }
        }
    }
    int ans = 0;
    if(u[0] == 0){
        que.front();
        que.pop();
    }
    while(ans < N){
        x = que.front();
        que.pop();
        for(int i=0; i<10-K; i++){
            ans = x*10+u[i];
            if(ans >= N){
                cout << ans;
                return 0;
            }else   que.push(ans);
        }
    }
}