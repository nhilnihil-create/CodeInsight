#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
// #include 
using namespace std;

void solve()
{
    string sa, sb, sc; cin >> sa >> sb >> sc;
    int ca, cb, cc;
    ca = sa.size();
    cb = sb.size();
    cc = sc.size();
    int turn = 0;
    while(1){
        switch(turn){
            case 0:
                if(!ca) {
                    cout << "A" << endl;return;
                }
                turn = sa[0]-'a';
                sa.erase(0, 1);
                break;
            case 1:
                if(!cb) {
                    cout << "B" << endl;return;
                }
                turn = sb[0]-'a';
                sb.erase(0,1);
                break;
            case 2:
                if(!cc) {
                    cout << "C" << endl;return;
                }
                turn = sc[0]-'a';
                sc.erase(0,1);
                break;
            default: 
                cout  << "Error" <<endl;
        }
        ca = sa.size();
        cb = sb.size();
        cc = sc.size();
    }
}

int main()
{
    solve();
    return 0;
}