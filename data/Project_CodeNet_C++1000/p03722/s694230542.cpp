#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<long>a(m);
    vector<long>b(m);
    vector<long>c(m);
    for(int i=0;i<m;i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    vector<long>score(n+1,-9999999999999999);
    bool chk = true;
    int count = 0;
    score[1] = 0;
    while(chk){
        chk = false;
        bool chkk = false;
        count++;

        for(int i=0;i<m;i++){
            if(score[a[i]]+c[i] > score[b[i]]){
                score[b[i]] = score[a[i]] + c[i];
                chk = true;
                if(b[i]==n)chkk=true;
            }
        }

        if(!chkk && count > 10*m)chk = false;
        if(count > 10*m)break;
    }
    if(!chk)cout<<score[n]<<endl;
    else cout<<"inf"<<endl;
}