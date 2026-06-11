#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll N , M , ans = 0;
    cin >> N >> M;

    vector<ll> ball(N, 0);
    vector<ll> ball_num(N, 1);
    ball[0] = 1;
    ll x , y;

    for(int i = 0; i < M; i++){
        cin >> x >> y;
        x--;
        y--;
        if(ball[x] == 1){
            ball[y] = 1;
            ball_num[y]++;
            ball_num[x]--;
            if(ball_num[x] == 0){
                ball[x] = 0;
            }
        }else{
            ball_num[y]++;
            ball_num[x]--;
        }
    }
    
    cout << accumulate(ball.begin(), ball.end(),0) << endl;

}