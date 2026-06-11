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
    int n = s.length();
    n -= 2;
    while(n>=2){
        int m = n/2;
        string res1 = "", res2="";
        for(int i=0;i<m;i++)   res1 += s[i];
        for(int i=m;i<n;i++)   res2 += s[i];
        
        if(res1==res2){
            cout<<n<<endl;
            return 0;
        }
        n -= 2;
    }
    return 0;
}

