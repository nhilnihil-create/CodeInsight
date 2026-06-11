/*
ID: learnin7
TASK: test
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
        
    ios_base::sync_with_stdio(0);
    //ofstream fout ("test.out");
    //ifstream fin ("test.in");
    //fin >> a >> b;
    //fout << a+b << endl;
    string s;
    cin>>s;
    int b=0,e=s.length()-1;
    while(b<e){
        if(s[b]!='A')   b++;
        else if(s[e]!='Z')   e--;
        else break;
    }
    cout<<e-b+1<<endl;
    return 0;
}

