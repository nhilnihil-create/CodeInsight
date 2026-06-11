    #include"bits/stdc++.h"
    using namespace std;
    int a,b;
     
    int main(){
    	cin>>a>>b;
    	if(a>0)cout<<"Positive";
    	else if(a==0||(a<0&&b>0))cout<<"Zero";
    	else if((abs(b)-abs(a))%2!=0)cout<<"Positive";
    	else cout<<"Negative";
    	return 0;
    }