#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main(){
    
    int N;
    string s,t;
    cin >> N;
    cin >> s >> t;

    for(int i = 0;i < N;i++){
        //cout << r.substr(0,i) <<" "<< t.substr(0,i)<<endl;
        if(s.substr(i)==t.substr(0,N-i)){
            
            cout << N + i<<endl;
            return 0;
        }
        
    }

    cout <<s.size() + t.size() <<endl;
    return 0;
}
    
    

