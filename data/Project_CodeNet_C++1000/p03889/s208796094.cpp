#include<bits/stdc++.h>
using namespace std;
#define maxn 500000
char a[maxn],b[maxn];
int s=1;
int main(){
    while(cin>>a[s]){
        s++;
    }
    for(int i=1;i<=s-1;i++){
        b[i]=a[i];
    }
    for(int i=1;i<=s/2;i++){
        swap(a[i],a[s-i]);
    }

    for(int i=1;i<=s-1;i++){
        if(a[i]=='b'){a[i]='d';continue;
        }
         if(a[i]=='d'){a[i]='b';continue;
         }
        if(a[i]=='p'){a[i]='q';continue;
        }
        if(a[i]=='q'){a[i]='p';continue;
        }
    }
    
    for(int i=1;i<=s-1;i++){
        if(a[i]!=b[i]){
            cout<<"No"<<endl;return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}