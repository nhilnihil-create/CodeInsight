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
    unsigned long long  q,h,s,d,n;
    cin>>q>>h>>s>>d;
    cin>>n;
    unsigned long long n1 = min(s,min(2*h,min(4*q,2*q+h)));
    unsigned long long n2 = min(d, 2*n1);
    if(n==1){
        cout<<n1<<endl;
    }
    else if(n==2){
        cout<<n2<<endl;
    }
    else{
        unsigned long long sum=(n/2)*n2 + (n%2)*n1;
        /*
        unsigned long long fi = n1, se=n2;
        for(unsigned long long i=3;i<=n;i++){
            if(i%2==0){
                sum = min(n2+fi, (i/2)*se);
            } 
            else{
                sum = n2 + fi;
                n2=sum;
            }
            //sum = n1 + n2;
           // cout<<i<<": Starting with "<<n1<<" "<<n2<<" => "<<sum<<endl; 
            //n1 = n2;
            //n2 = sum;
        }
        */
        cout<<sum<<endl;
    }
    return 0;
}

