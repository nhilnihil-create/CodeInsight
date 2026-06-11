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
    int n;
    string s;
    cin>>n;
    cin>>s;
    int x=0;
    int max_x=x;
    for(int i=0;i<n;i++){
        if(s[i]=='I')   x++;
        else if(s[i]=='D')  x--;
        max_x = max(max_x,x);
    }
    cout<<max_x<<endl;
    return 0;
}

