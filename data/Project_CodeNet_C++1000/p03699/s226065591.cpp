#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    int s[N];
    for(int i = 0; i <N;i++)cin >> s[i];
    
    sort(s,s+N);
    int sum = 0;
    for(int i = 0; i <N;i++)sum +=s[i];
    
    for(int i = 0; i <N;i++){
        if(sum%10!=0){
            cout << sum <<endl;
            return 0;
        }else{
            if(s[i]%10!=0)sum -= s[i];
        }
        
    }
    cout << 0 <<endl;
}
    
    

