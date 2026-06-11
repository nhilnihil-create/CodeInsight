#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
//#define int long long  
int main(){
    string s[30][30];
    int H,W;
    cin >> H >> W;
    REP(i,H){
        REP(j,W){
            cin >> s[i][j];
            if(s[i][j]=="snuke"){
                cout << (char)('A'+j) << i+1 << endl;
            }
        }
    }
	return 0;
}
