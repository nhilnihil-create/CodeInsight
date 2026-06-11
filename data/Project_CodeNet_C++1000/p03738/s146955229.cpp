#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    string a, b;
    cin >> a >> b;

    if(a.size()>b.size()){
        cout << "GREATER" << endl;
    }
    else if(b.size()>a.size()){
        cout << "LESS" << endl;
    } 
    else{
        rep(i, a.size()){
            int tmpa = a.at(i) - '0';
            int tmpb = b.at(i) - '0';
            if(tmpa<tmpb){
                cout << "LESS" << endl;
                return 0;
            }
            else if(tmpa > tmpb){
                cout << "GREATER" << endl;
                return 0;
            }
            else continue;
        }

        cout << "EQUAL" << endl;
    }
    return 0;
}
