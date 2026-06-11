#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e3+5;
char a[N];
int numn=0;
int nums=0;
int numw=0;
int nume=0;
bool check(){
    return (nums==numn||(nums&&numn))&&(nume==numw||(nume&&numw));
}
int main(){
    cin >> a;
    int n=strlen(a);
    
    for(int i=0;i<n;i++){
        if(a[i]=='S')nums++;
        if(a[i]=='E')nume++;
        if(a[i]=='W')numw++;
        if(a[i]=='N')numn++;
    }
    if(check()){
        cout << "Yes";
    
    }else{
        cout << "No";
    }
}