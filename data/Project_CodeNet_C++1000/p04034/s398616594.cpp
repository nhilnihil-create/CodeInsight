#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M,ans=0;
    cin >> N >> M;

    vector<int> x(M+10),y(M+10);

    vector<int> ball(N+10);

    vector<bool> red(N+10);

    for(int i = 1;i <= M;i++){
        cin >> x.at(i); 
        cin >> y.at(i);
    }

    for(int i = 1;i <= N;i++){
        ball.at(i) = 1;
        if(i == 1)
            red.at(i) = true;
        else
            red.at(i) = false;
    }

    for(int i = 1;i <= M;i++){
            
        if(red.at(x.at(i)) == true && ball.at(x.at(i)) >= 2){
            red.at(y.at(i)) = true;
            ball.at(x.at(i))--;
            ball.at(y.at(i))++;
        }else if(red.at(x.at(i)) == true && ball.at(x.at(i)) == 1){
            red.at(x.at(i)) = false;
            red.at(y.at(i)) = true;
            ball.at(x.at(i))--;
            ball.at(y.at(i))++;
        }else{
            ball.at(x.at(i))--;
            ball.at(y.at(i))++;
            }
        


    }

    for(int i = 1;i <= N;i++){
        if(red.at(i) && ball.at(i) >= 1){
            ans++;
        }
    }


    cout << ans << endl;


}