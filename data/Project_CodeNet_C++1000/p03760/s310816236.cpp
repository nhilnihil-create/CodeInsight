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
    string o,e;
    cin>>o;
    cin>>e;
    int n = o.length(), m = e.length();
    for(int i=1;i<=n+m;i++){
        if(i%2==1)
            cout<<o[i/2];
        else
            cout<<e[(i/2)-1];
    }
    cout<<"\n";

    return 0;
}

