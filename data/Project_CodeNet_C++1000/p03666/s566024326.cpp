#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int mod = 1e9+7;

int main(){
    ll N,A,B,C,D;
    cin>>N>>A>>B>>C>>D;

    ll dif = abs(B-A);

    bool check = false;
        
    for(int i=0; i<N; i++){
        ll smallC = C*i;
        ll bigC = C*(N-1-i);
        ll smallD = D*i;
        ll bigD = D*(N-1-i);
        if(smallC - bigD <= dif && dif <= smallD - bigC){
            check = true;
        }
    }

    if(check) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;

}