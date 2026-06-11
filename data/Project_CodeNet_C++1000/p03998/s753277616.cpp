#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    string A,B,C;
    cin >> A >> B >> C;
    int numa,numb,numc;
    numa = A.size();
    numb = B.size();
    numc = C.size();
    int ca=0,cb=0,cc=0;
    char T = 'a';
    while(1){
        if(T=='a'){
            if(ca==numa){
                cout << "A" << endl;
                return 0;
            }
            T = A[ca];
            ca++;
        }else if(T=='b'){
            if(cb==numb){
                cout << "B" << endl;
                return 0;
            }
            T = B[cb];
            cb++;
        }else{
            if(cc==numc){
                cout << "C" << endl;
                return 0;
            }
            T = C[cc];
            cc++;
        }
    }
    return 0;
}