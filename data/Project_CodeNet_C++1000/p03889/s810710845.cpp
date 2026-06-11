#include<iostream>
#include<string>
#include<map>
using namespace std;
char change(char a){
	if(a=='p') return 'q';
	if(a=='q') return 'p';
	if(a=='b') return 'd';
	return 'b';
	
 }
string change(string a){
    int len=a.length();
    
    for(int i=0;i<len/2;++i){
        swap(a[i],a[len-1-i]);
    }
    for(int i=0;i<len;++i){
        a[i]=change(a[i]);
    }
    return a;
}
int main(){
    string s;
    cin>>s;
    if(s==change(s)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}