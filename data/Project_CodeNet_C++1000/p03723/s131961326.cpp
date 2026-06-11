#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase=1;
    //cin>>testcase;
    for(int p=0;p<testcase;p++){
        ll a=0,b=0,c=0,counter=0;
	cin>>a>>b>>c;
        bool k=true;
        while(a%2==0 && b%2==0 && c%2==0)
        {   int tempa=0,tempb=0,tempc=0;
            tempa=a;
            tempb=b;
            tempc=c;
            a=(tempb+tempc)/2;
            b=(tempa+tempc)/2;
            c=(tempa+tempb)/2;
            counter++;
	if(a==b && b==c){
	cout<<"-1";
k=false;	
break;
	
	}
        }
if(k)
        cout<<counter;
        
        
        
    }

    return 0;
}
