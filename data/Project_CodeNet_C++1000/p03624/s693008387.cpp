#include<bits/stdc++.h>
using namespace std;

int k,j,x;
string a;
char i,z;
bool ada[27],valid;


int main(){
	cin>>a;
    for(i='a';i<='z';i++){
        for(j=0;j<=a.length()-1;j++){
            x=0;
            if(a[j]==i){
                x=i-'a'+1;
                ada[x]=true;
            }
        }
    }
    valid=false;
    for(k=1;k<=26;k++){
        if(ada[k]==false){
            valid=true;
            z='a'+k-1;
            cout<<z;
            break;
        }
    }
    if(valid==false){
        cout<<"None";
    }
}