#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)
#define PI 3.14159265359
#define EPS 0.0000000001
#define MOD 1000000007
//cout << std::fixed << std::setprecision(15) << y << endl;


int main(){
    string sa, sb, sc;
    cin >> sa >> sb >> sc;

    ll pa = 0, pb = 0, pc = 0;
    ll turn = 0;
    ll winner = -1;
    while(1){
        if(turn == 0){
            if(pa == sa.size()){
                winner = 0;
                break;
            }else{
                if(sa[pa] == 'a'){
                    turn = 0;
                }else if(sa[pa] == 'b'){
                    turn = 1;
                }else{
                    turn = 2;
                }
                pa++;
            }
        }else if(turn == 1){
            if(pb == sb.size()){
                winner = 1;
                break;
            }else{
                if(sb[pb] == 'a'){
                    turn = 0;
                }else if(sb[pb] == 'b'){
                    turn = 1;
                }else{
                    turn = 2;
                }
                pb++;
            }
        }else{
            if(pc == sc.size()){
                winner = 2;
                break;
            }else{
                if(sc[pc] == 'a'){
                    turn = 0;
                }else if(sc[pc] == 'b'){
                    turn = 1;
                }else{
                    turn = 2;
                }
                pc++;
            }
        }
    }

    if(winner == 0){
        cout << "A" << endl;
    }else if(winner == 1){
        cout << "B" << endl;
    }else{
        cout << "C" << endl;
    }

    return 0;
}