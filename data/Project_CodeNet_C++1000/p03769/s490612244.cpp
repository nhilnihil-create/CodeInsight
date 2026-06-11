# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <cstring>
# include <stdio.h>
# include <map>
# include <queue>

# define ll long long
# define pii pair<int,int>
# define FOR(a,b) for(int a=1; a<=b; a++)
# define REP(a,b) for(int a=0; a<b; a++)
# define FORU(a,b,c) for(int a=b; a<=c; a++)
# define FORD(a,b,c) for(int a=b; a>=c; a--)

using namespace std;

ll N;
deque<int> dq;
int cur=0;

void construct(ll x){
    if(x==1) return;
    if(x & 1){
        construct(x-1);
        dq.push_front(++cur);
    }
    else{
        construct(x/2);
        dq.push_back(++cur);
    }
}

int main(){

    ios :: sync_with_stdio(false);
    cin >> N;
    construct(N+1);

    cout << 2*((int)dq.size()) << endl;
    REP(i,dq.size()) cout << dq[i] << " ";
    FOR(i,cur) cout << i << " ";
    cout << endl;

    return 0;
}