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
    int a[n];
    int tot = 0;
    for(int i=0;i<n;i++)    cin>>a[i], tot+=a[i];
    //cout<<tot<<endl;
    if(tot%10!=0){
        cout<<tot<<endl;
        return 0;
    }
    //sort(a,a+n);
    int max_tot=INT_MIN;
    //tot=0;
    bool nonzero = false;
    for(int i=0;i<n;i++)
    {   
        if(a[i]%10!=0)
            nonzero=true, max_tot = max(max_tot, tot-a[i]); 
    }
    if(nonzero) cout<<max_tot<<endl;
    else        cout<<0<<endl;
    return 0;
}

