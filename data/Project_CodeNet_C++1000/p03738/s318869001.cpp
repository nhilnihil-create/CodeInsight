#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    string A,B;
    cin>>A>>B;
    if(A.size()>B.size()){
        cout << "GREATER" << endl;
        return 0;
    }else if(A.size()<B.size()){
        cout << "LESS" << endl;
        return 0;
    }else{
        rep(i,A.size()){
            if(A.at(i)==B.at(i)){
                continue;
            }else if(A.at(i)>B.at(i)){
                cout << "GREATER" << endl;
                return 0;
            }else{
                cout << "LESS" << endl;
                return 0;
            }
        }


    }
    cout << "EQUAL" << endl;
    return 0;
}