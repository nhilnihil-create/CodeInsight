#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    char w[105];
    int i,j,p=1;
    cin>>w;
    for( i=0;i<strlen(w);i++){
        if(w[i]=='0')
        continue;
        for(j=i+1;j<strlen(w);j++){
            if(w[i]==w[j]&&w[i]>='a'&&w[i]<='z'){
                p++;
                w[j]='0';
            }
        }
        if(p%2!=0){
            cout<<"No"<<endl;
            return 0;
        }
        p=1;
    }
    cout<<"Yes"<<endl;
    return 0;
}