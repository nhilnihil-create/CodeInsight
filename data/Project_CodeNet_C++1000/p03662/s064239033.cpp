#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>

using namespace std;

#define INF 1 << 29
#define LL long long int

vector<vector<int>> t(100001);
vector<bool> close(100001,false);
queue<LL> fen,snu;

LL fnum,snum;


LL bfs(){
    while(!fen.empty() || !snu.empty()){
        for(int j = fen.size(); j > 0; j--){
            LL tmp = fen.front();
            fen.pop();
            for(int i = 0; i < t[tmp].size(); i++){
                if(!close[t[tmp][i]]){
                    fen.push(t[tmp][i]);
                    fnum++;
                    close[t[tmp][i]] = true;
                }
            }
        }
        for(int j = snu.size(); j > 0; j--){
            LL tmp = snu.front();
            snu.pop();
            for(int i = 0; i < t[tmp].size(); i++){
                if(!close[t[tmp][i]]){
                    snu.push(t[tmp][i]);
                    snum++;
                    close[t[tmp][i]] = true;
                }
            }
        }
    }
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    LL n;
    cin >> n;


    for(LL i = 0; i < n-1; i++){
        LL a,b;
        cin >> a >> b;
        t[a].push_back(b);
        t[b].push_back(a);
    }

    close[1] = close[n] = true;
    fen.push(1);
    snu.push(n);

    fnum = 0;
    snum = 0;

    bfs();

    if(fnum > snum){
        cout << "Fennec" << endl;
    }else{
        cout << "Snuke" << endl;
    }

    return 0;
}