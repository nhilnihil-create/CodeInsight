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
    int h,w;
    cin>>h>>w;
    vector<string> c(h);
    for(int i=0;i<h;i++){
        cin>>c[i];
    }
    //cout<<"dkjsnke\n";
    vector<string> q;
    for(int i=0;i<h;i++){
            //cout<<i<<" "<<(i)/2<<" "<<c[(i)/2]<<endl;:
                q.push_back(c[i]);
                q.push_back(c[i]);
        }
        //cout<<res<<endl;
        //q[i] = res;
       // cout<<i<<" "<<q[i]<<endl;
    //cout<<"yo\n";
    for(int i=0;i<2*h;i++){
        cout<<q[i]<<endl;
    }
    return 0;
}

