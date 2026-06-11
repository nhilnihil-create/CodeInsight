#include<iostream>
#include<algorithm>

using namespace std;

#define REP(s,e) for(int i=(s);i<(e);i++)

int main(){
    string A,B,C;
    int sa='A'-'a';

    cin>>A>>B>>C;

    cout<<(char)(sa+A[0])<<(char)(sa+B[0])<<(char)(sa+C[0])<<endl;
}
