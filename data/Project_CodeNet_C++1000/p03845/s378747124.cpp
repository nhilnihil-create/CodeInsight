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
    cin>>n;
    int t[n];
    for(int i=0;i<n;i++)    cin>>t[i];
    int m;
    cin>>m;
    while(m--){
        int p,x;
        cin>>p>>x;
        p--;
        int sum=0;
        for(int i=0;i<n;i++){
            if(i==p)    sum +=x;
            else        sum +=t[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}

