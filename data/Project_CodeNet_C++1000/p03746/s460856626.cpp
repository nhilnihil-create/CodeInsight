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
    int N,M;
    cin >> N >> M;
    vector<vector<int>> edge(N, vector<int>(0));
    vector<int> pass1(0);
    vector<int> pass2(0);
    vector<bool> used(N);
    for(int i = 0; i < N; i++){
        used.at(i) = 0;
    }
    
    
    for(int i = 0; i < M; i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        edge.at(a).push_back(b);
        edge.at(b).push_back(a);
        if(i == 0){
            pass1.push_back(a);
            pass2.push_back(b);
            used.at(a) = 1;
            used.at(b) = 1;
        }
    }
    
    
    
    
    int cnt = 0;
    while(1){
        cnt++;
        bool l = 0;
        int a = pass1.at(pass1.size()-1);
        for(int i = 0; i < edge.at(a).size(); i++){
            if( used.at( edge.at(a).at(i) ) == 0 ){
                pass1.push_back(edge.at(a).at(i));
                used.at( edge.at(a).at(i) ) = 1;
                l = 1;
                break;
            }
        }
        if(l == 1)continue;
        
        int b = pass2.at(pass2.size()-1);
        for(int i = 0; i < edge.at(b).size(); i++){
            if( used.at( edge.at(b).at(i) ) == 0 ){
                pass2.push_back(edge.at(b).at(i));
                used.at( edge.at(b).at(i) ) = 1;
                l = 1;
                break;
            }
        }
        if(l == 0){
            break;
        }
    }
    
    cout << pass1.size() + pass2.size() << endl;
    
    for(int i = 0; i < pass2.size(); i++){
        cout << pass2.at( pass2.size() - 1 - i   ) + 1 << " ";
    }
    
    for(int i = 0; i < pass1.size(); i++){
        if(i != pass1.size()-1){
            cout << pass1.at(i) + 1 << " ";
        }else{
            cout << pass1.at(i) + 1;
        }
    }
}
