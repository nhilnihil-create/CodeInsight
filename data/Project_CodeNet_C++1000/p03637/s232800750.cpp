#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
#define ll long long
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    int N;
    cin>>N;
    int tmp=0;
    int cnt4=0,cnt2=0,cntodd=0;
    rep(i,N){
        cin>>tmp;
        if(tmp%2!=0){
            cntodd++;
        }else if(tmp%4!=0){
            cnt2++;
        }else{
            cnt4++;
        }
    }
//    cout << cnt4 << ":" << cnt2 << ":" << cntodd << endl;
    //Nが偶数の時⇒奇数が過半数ならOUT;
    //Nが奇数の時⇒奇数が過半数+1ならOUT;
    if(N%2==0){
        if(cntodd>N/2){
            cout << "No" << endl;
            return 0;
        }
    }
    if(N%2!=0){
        if(cntodd>N/2+2){
            cout << "No" << endl;
            return 0;
        }
    }
    //奇数の隣は4の倍数が必須
    //逆に言うとそれさえ守れていればあとは偶数偶数で並ぶのでOK
    //4の倍数の個数>=奇数の個数なら無条件でOK
    if(cnt4>=cntodd){
        cout << "Yes" << endl;
        return 0;
    }
    //4の倍数の個数+1<奇数の個数なら強制OUT
    if(cnt4+1<cntodd){
        cout << "No" << endl;
        return 0;
    }
    //4の倍数の個数+1=奇数の個数の場合
    //き、４、き、４、き...と並べていき最後にきが来るので偶数が残ってたらOUT
    if(cnt4+1==cntodd){
        if(cnt2!=0){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }


    return 0;
}