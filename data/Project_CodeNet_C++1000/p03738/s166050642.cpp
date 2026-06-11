#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("../input.txt","r",stdin);

    string A,B;
    cin >> A >> B;

    bool isEqualSize = ((ll)A.size() == (ll)B.size());
    bool isAGreater = ((ll)A.size() > (ll)B.size());

    if(isAGreater){
        cout << "GREATER\n";
    }else if(isEqualSize){
        if(A == B){
            cout << "EQUAL\n";
        }else{
            for (ll i = 0; i < A.size(); ++i) {
                if((A[i]-'0') < (B[i]-'0')){
                    cout << "LESS\n";
                    return 0;
                }else if((A[i]-'0') > (B[i]-'0')){
                    cout << "GREATER\n";
                    return 0;
                }
            }
            cout << "EQUAL\n";
            return 0;
        }
    }else{
        cout << "LESS\n";
    }

}