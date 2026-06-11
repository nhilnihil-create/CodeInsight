#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
//typedef pair<int,int> P;
//priority_queue<int> pque;
//priority_queue<int, vector<int>, greater<int>> pque;
ll INFL = 1000000000000000010;//10^18 = 2^60
int INF = 2000000000;//10^9
ll MOD  = 1000000007;
int main(void){
    ll N,L,T;
    cin >> N >> L >> T;
    vector<ll> X(N);
    vector<bool> W(N);//０なら時計回り,１なら反時計回り
    for(int i = 0; i < N; i++){
        cin >> X.at(i);
        int a;
        cin >> a;
        a--;
        W.at(i) = a;
    }
    
    vector<ll> afterX(N);
    for(int i = 0; i < N; i++){
        if(W.at(i)){//反時計回り
            afterX.at(i) = (((X.at(i) - T) % L) + L) % L;
        }else{
            afterX.at(i) = (X.at(i) + T) % L;
        }
    }
    
    ll through = 0;
    for(int i = 0; i < N; i++){
        if(W.at(0) != W.at(i)){
            
            ll sa;
            if(!W.at(0)){//時計回り
                sa =  X.at(i) - X.at(0);
            }
            else{//反時計回り
                sa =  X.at(0) + (L - X.at(i));
            }
            
            if(T * 2 >= sa){
                through += 1 + (2 * T - sa) / L;
            }
        }
    }
    
    ll position = 0;
    
    
    if(W.at(0)){//反時計回り
        position -= through;
    }else{//時計回り
        position += through;
        
    }
    
    position = ((position % N) + N) % N;
    //Pがposition番目に出力されたい
    
    ll P = afterX.at(0);
    
    
    sort(afterX.begin(), afterX.end());
    
    bool l = 0;
    ll I1;
    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(afterX.at(i) == P){
            cnt++;
            if(cnt == 1){
                I1 = i;
            }
            else if(cnt == 2){
                l = 1;
            }
        }
    }
    //I1はPの場所
    
    if(l){
        if( (W.at(0) + through) % 2 == 1){
            if(W.at(0))I1++;
        }
        else{
            if(!W.at(0))I1++;
            
        }
    }
    
    
    for(int i = 0; i < N; i++){
        cout << afterX.at((((I1 - position + i) % N) + N) % N) << endl;
    }
    
}
