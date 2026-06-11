#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    char s;
    int ans=0,x=0;
    for(int i=0;i<n;i++){
        cin>>s;
        if(s=='I')x++;
        else if(s=='D')x--;
        if(x>ans)ans=x;
    }
    cout<<ans<<endl;
    return 0;
}