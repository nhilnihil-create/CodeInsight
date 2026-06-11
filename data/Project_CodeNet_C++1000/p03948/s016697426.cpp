#include <iostream>
using namespace std;
int main(void){
    int n,t;
    cin>>n>>t;
    int MIN=1<<30;
    int root=0,cnt=0;
    
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        MIN=min(a,MIN);
        if(a-MIN>root){
            root=a-MIN;
            cnt=1;
        }
        else if(a-MIN==root){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
