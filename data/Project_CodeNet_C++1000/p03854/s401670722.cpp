#include<iostream>
using namespace std;
bool check(string main,string test,int start){
    string result="";
    if(start+test.size()>main.size())
    return false;
    for(int i=start;i<start+test.size();i++){
        result+=main[i];
    }
    if(result==test)
    return true;
    return false;
}
int main(){
    string s;
    cin>>s;
    int start=0;
    bool no=0;
    while(start!=s.size()){
        if(check(s,"dreamer",start)){
            start+=7;
            if(start!=s.size()&&s[start]=='a'){
                start-=2;
            }
            continue;
        }
        else
        if(check(s,"dream",start)){
            start+=5;
            continue;
        }
        else
        if(check(s,"eraser",start)){
            start+=6;
            continue;
        }
        else
        if(check(s,"erase",start)){
            start+=5;
            continue;
        }
        else{
            no=1;
            break;
        }
    }
    if(!no){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}