#include<bits/stdc++.h>
using namespace std;

int i;
string a,b;


int main(){
	cin>>a>>b;
    for(i=0;i<=b.length()-1;i++){
        cout<<a[i]<<b[i];
    }
    if(a.length()>b.length()){
        cout<<a[a.length()-1];
    }
}
