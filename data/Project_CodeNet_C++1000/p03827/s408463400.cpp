#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    string ss;
    cin>>ss;
    int x=0,temp=0;
    for(int i=0;i<ss.size();i++){
    
    	if(ss[i]=='I')x++;
    	else x--;
        if(x>=temp)temp=x;
    }
    cout<<temp;
}