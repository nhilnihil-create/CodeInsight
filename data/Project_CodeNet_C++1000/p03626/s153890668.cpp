#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#define MOD 1000000007
#define INT long long int
#define REP(i,n) for(int(i)=0;(i)<(n);(i)++) 
using namespace std;
const long long INF = numeric_limits<long long>::max();


int main()
{
    int N;
    cin>>N;
    char s1[N+1];
    char s2[N+1];
    s1[N] = '?';
    s2[N] = '?';
    REP(i,N){
        cin>>s1[i];
    }
    REP(i,N){
        cin>>s2[i];
    }

    INT ans = 3;
    int state[N];
    int cnt=0;
    int idx=0;
    while (idx < N){
        if (s1[idx] == s1[idx+1]){
            state[cnt] = 1;
            idx++;
        }else if(s1[idx] == s2[idx]){
            state[cnt] = 0;
        }
        cnt++;
        idx++;
    }
    int L = cnt;
    REP(i,L){
        if (state[i] == 1){
            if (i!=0 && state[i-1] == 1){
                ans *= 3;
                ans %= MOD;
            }else{
                ans *= 2;
                ans %= MOD;
            }
        }else{
            if (i == 0) continue;
            else if(state[i-1] == 0){
                ans *= 2;
                ans %= MOD;
            }
        }
    }
    cout << ans << endl;\

    return 0;
}