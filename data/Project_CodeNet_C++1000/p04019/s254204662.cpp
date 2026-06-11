#include <bits/stdc++.h>
using namespace std;
 

    using Graph = vector<vector<int>>;
 
int main() {

    string s;
    cin>>s;


    int cnt_n=0,cnt_w=0,cnt_s=0,cnt_e=0;
    for(int i=0;i<s.size();i++){
        if(s.at(i)=='N')
            cnt_n++;
        else if(s.at(i)=='W')
            cnt_w++;
        else if(s.at(i)=='S')
            cnt_s++;
        else //E
            cnt_e++;
    }

    bool cond1 = (cnt_n>=1 && cnt_s>=1) && (cnt_w>=1 && cnt_e>=1);
    bool cond2 = (cnt_n==0 && cnt_s==0) && (cnt_w>=1 && cnt_e>=1);
    bool cond3 = (cnt_n>=1 && cnt_s>=1) && (cnt_w==0 && cnt_e==0);

    if(cond1 || cond2 || cond3)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

 	return 0;
}