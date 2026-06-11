#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n + 1); i++)
int main() {
    string S;
    cin>>S;
    int a=S.size();
    
    for(int i=a; 0<i; i--){
      	if(i!=a){
        if(i%2==0){
            bool t=true;
            rep(j,i/2){
                if(S[j]!=S[j+i/2]){
                    j+=i;
                    t=false;
                }
            }
            if(t==true){
                cout<<i<<endl;
                break;
            }
        }
        else{
            continue;
        }
        }
    }
}