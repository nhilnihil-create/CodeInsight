#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
using namespace std;

bool put_nums(int flag[], int now, string s, int n)
{
    if(now==n-2 || now==n-1){
        if(s[now]=='x' && flag[now+2]==flag[now+1]*(-flag[now])) return true;
        else if(s[now]=='o' && flag[now+2]==flag[now+1]*flag[now]) return true;
        else return false;
    }else{
        if(s[now]=='x'){
            flag[now+2]=flag[now+1]*(-flag[now]);
        }else{
            flag[now+2]=flag[now+1]*flag[now];
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int flag[n+2], ans=0, cnt=0;//1:sheep, -1:wolf
    fill(flag, flag+n+1, 0);
    flag[0]=1, flag[1]=1, flag[n]=1, flag[n+1]=1;
    while(cnt<n){
        if(put_nums(flag, cnt, s, n)==false) break;
        cnt++;
    }
    if(cnt==n) ans=1;

    if(ans==0){
        cnt=0;
        fill(flag, flag+n+1, 0);
        flag[0]=-1, flag[1]=1, flag[n]=-1, flag[n+1]=1;
        while(cnt<n){
            if(put_nums(flag, cnt, s, n)==false) break;
            cnt++;
        }
        if(cnt==n) ans=1;
    }

    if(ans==0){
        cnt=0;
        fill(flag, flag+n+1, 0);
        flag[0]=-1, flag[1]=-1, flag[n]=-1, flag[n+1]=-1;
        while(cnt<n){
            if(put_nums(flag, cnt, s, n)==false) break;
            cnt++;
        }
        if(cnt==n) ans=1;
    }

    if(ans==0){
        cnt=0;
        fill(flag, flag+n+1, 0);
        flag[0]=1, flag[1]=-1, flag[n]=1, flag[n+1]=-1;
        while(cnt<n){
            if(put_nums(flag, cnt, s, n)==false) break;
            cnt++;
        }
        if(cnt==n) ans=1;
    }

    if(ans==1){
        for(int i=1; i<=n; i++){
            if(flag[i]==1){
                cout << 'S';
            }else{
                cout << 'W';
            }
        }
    }else{
        cout << -1 << endl;
    }

    return 0;
}