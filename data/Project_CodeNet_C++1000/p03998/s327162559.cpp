#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
//rep…「0からn-1まで」の繰り返し
#define rep2(i,s,n) for(long long i=s; i<=(long long)(n);i++)
//rep2…「sからnまで」の繰り返し
#define repr(i,s,n) for(long long i=s;i>=(long long)(n);i--)
//repr…「ｓからnまで」の降順の繰り返し

typedef long long ll;

const int inf = 1e9+7;
const int mod = 1e9+7;

int main(){
    string A,B,C;
    cin>>A>>B>>C;

    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    reverse(C.begin(),C.end());

    char x='a',ans;

    for(;;){
        if(x=='a'){
            if(A.size()==0){
                ans='A';
                break;
            }
            x=A[A.size()-1];

            A.pop_back();
        }
        else if(x=='b'){
            if(B.size()==0){
                ans='B';
                break;
            }
            x=B[B.size()-1];

            B.pop_back();
        }
        else if(x=='c'){
            if(C.size()==0){
                ans='C';
                break;
            }
            x=C[C.size()-1];
            C.pop_back();
        }
    }
    cout<<ans<<endl;
}
