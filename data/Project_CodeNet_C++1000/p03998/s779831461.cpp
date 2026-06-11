#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    string SA, SB, SC;
    cin >> SA >> SB >> SC;

    reverse(SA.begin(), SA.end());
    reverse(SB.begin(), SB.end());
    reverse(SC.begin(), SC.end());

    char next_turn = 'a';
    while(true){
        switch (next_turn)
        {
            case 'a':
                if(SA.size()==0){
                    cout << "A" << endl;
                    return 0;
                }

                next_turn = SA[SA.size()-1];
                SA.pop_back();
                break;
            case 'b':
                if(SB.size()==0){
                    cout << "B" << endl;
                    return 0;
                }

                next_turn = SB[SB.size()-1];
                SB.pop_back();
                break;
            case 'c':
                if(SC.size()==0){
                    cout << "C" << endl;
                    return 0;
                }
                next_turn = SC[SC.size()-1];
                SC.pop_back();
                break;
            default:
                break;
        }

    }
    return 0;
    
}
