#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<algorithm>
#include <vector>
using namespace std;

int main(){
    string s;cin>>s;
    int count=(1<<20);
    for (char i='a';i<'z'+1;i++){
        int now=0;
        int m=0;
        for(int j=0;j<s.size();j++){
            if(s[j]==i){
                now=0;
            }

            else {
                now+=1;
                m=max(now,m);
                }
            }
    count=min(m,count);
    }
    
cout<<count<<endl;
}
