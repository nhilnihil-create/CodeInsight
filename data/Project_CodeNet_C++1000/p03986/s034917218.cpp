#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl
typedef long long ll;
const ll MOD = 1000000007;
 
using namespace std;

int main(){
    string X;   cin >> X;
    int l = X.length();
    int cnt = 0;
    queue<int> que;
    for(int i=0; i<l; i++){
        if(i == 0)  cnt++;
        else{
            if(X[i] == 'S'){
                if(X[i-1] == 'T'){
                    que.push(cnt);
                    cnt = 0;
                }
                cnt++;
            }else{
                if(X[i-1] == 'S'){
                    que.push(cnt);
                    cnt = 0;
                }
                cnt++;
            }
        }
    }
    que.push(cnt);
    int s, t, cs;
    if(X[0] == 'T'){
        t = que.front();
        que.pop();
    }
    cnt = 0;
    cs = 0;
    while(!que.empty()){
        s = que.front();
        que.pop();
        if(!que.empty()){
            t = que.front();
            que.pop();
            cnt += (s-t);
            cs += s;
            if(cnt <= 0){
                l -= 2*cs;
                cs = 0;
                cnt = 0;
            }
        }else{
            break;
        }
    }
    l -= 2*(cs-cnt);
    cout << l << endl;
    return 0;
}