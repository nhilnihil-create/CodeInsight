#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,A,B;
    cin>>N>>A>>B;
    string s;
    cin>>s;
    int sum = A + B;
    int currentOverseasStudent = 0;
    int noStudentsPassed = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='c'){
            cout<<"No"<<endl;
        }else if(s[i]=='a'){
            if(noStudentsPassed < sum){
                noStudentsPassed++;
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
            
        }else if(s[i]=='b'){
            if(noStudentsPassed < sum && currentOverseasStudent < B){
                currentOverseasStudent++;
                noStudentsPassed++;
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}