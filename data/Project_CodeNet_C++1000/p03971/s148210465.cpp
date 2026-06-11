#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main(){
    
    int N,A,B;
    cin >> N >> A >> B;
    string S;
    cin >> S;
    int ans = 0;
    int bns = 0;
    for(int i = 0; i < N;i++){
        
        if(S[i]=='a'&&ans<A+B){
            ans++;cout << "Yes"<<endl;
        }else if(S[i]=='b' && bns<B && ans<A+B){
            ans++;bns++;cout <<"Yes"<<endl;
        }else{
            cout <<"No"<<endl;
        }
    }
    
    
}
    
    

