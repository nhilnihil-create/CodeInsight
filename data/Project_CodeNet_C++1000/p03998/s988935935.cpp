#include <bits/stdc++.h>
const double PI = acos(-1);
#define rep(i, n) for (int i = 0; i < (int)(n); i++ )
using namespace std;
int main() {
    string sa, sb, sc;
    cin >> sa >> sb >> sc;
    int num = 'a';
    while(true){
        if(num == 97){
            if(sa.empty()){
                cout << "A" << endl;
                break;
            }
            else{
                num = sa.at(0);
                sa.erase(0,1);
            }
        }
        else if(num == 98){
            if(sb.empty()){
                cout << "B" << endl;
                break;
            }
            else{
                num = sb.at(0);
                sb.erase(0,1);
            }
        }
        else if(num == 99){
            if(sc.empty()){
                cout << "C" << endl;
                break;
            }
            else{
                num = sc.at(0);
                sc.erase(0,1);
            }
        }
    }
}
