#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#define MOD 1000000007
#define INT long long int
#define REP(i,n) for(int(i)=0;(i)<(n);(i)++) 
using namespace std;
const long long INF = numeric_limits<long long>::max();
#include <map>
#include <queue>

bool solve(priority_queue<int>& que, int h, int w, int cnt){
    if ((h==0||w==0)||(h*w)==1) {
        for (int i=0;i<cnt;i++){
            int tmp=que.top();
            if (tmp>=2){
                tmp-=2;
                que.pop();
                que.push(tmp);
            }else return false;
        }
        return true;
    }
    else{
        if ((h==1 || w==1)){
            h = max(h,w);
            w = 1;
            int tmp=que.top();
            if (tmp >= 2){
                tmp-=2;
                que.pop();
                que.push(tmp);
                solve(que,h-2,w,cnt);
            }else return false;
        }else{
            int tmp = que.top();
            if (tmp >= 4){
                tmp-=4;
                que.pop();
                que.push(tmp);
            }else return false;
            for (int i=0;i<(h-2)/2;++i){
                int tmp = que.top();
                if (tmp >= 4){
                    tmp-=4;
                    que.pop();
                    que.push(tmp);
                }else return false;
            }
            for (int i=0;i<(w-2)/2;++i){
                int tmp = que.top();
                if (tmp >= 4){
                    tmp-=4;
                    que.pop();
                    que.push(tmp);
                }else return false;
            }
            if (h%2 == 1)cnt++;
            if (w%2 == 1)cnt++;
            
            return solve(que,h-2,w-2,cnt);
        }
    }

}

int main()
{
    int H,W;
    cin>>H>>W;
    map<char,int> counter;
    char S[H][W];
    REP(i,H){
        REP(j,W) {
            cin>>S[i][j];
            counter[S[i][j]]++;
        }
    }
    priority_queue<int> que;
    for (pair<char,int> cur:counter){
        que.push(cur.second);
    }
    bool ans = solve(que,H,W,0);
    if (ans){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

    // for (pair<char, int> cur:counter){
    //     cout<<cur.first << ':'<<cur.second<<endl;
    // }


    return 0;
}