#include <bits/stdc++.h>
using namespace std;
struct point{double x;double y;};
int i,j,k,count1=0,count2=0;

int main(void){
    int n,a=0,b=0,A,B;
    char c;
    cin>>n>>A>>B;
    for(i=0;i<n;i++){
        cin>>c;
        if(c=='a'){
            a++;
            if(a<=(A+B)){
                cout<<"Yes"<<endl;
            }else{
                a--;
                cout<<"No"<<endl;
            }
        }
        if(c=='b'){
            a++;
            b++;
            if(b<=B&&(a<=(A+B))){
                cout<<"Yes"<<endl;
            }else{
                a--;
                b--;
                cout<<"No"<<endl;
            }
        }
        if(c=='c'){
            cout<<"No"<<endl;
        }
    }
}