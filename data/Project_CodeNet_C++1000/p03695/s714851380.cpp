#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++)
    {
        cin >> A.at(i);
    }
    int min=0,max=0,count=0;
    vector<bool> B(8);
    for(int i=0; i<8; i++) B.at(i)=false;
    for(int i=0; i<N; i++)
    {
        if(A.at(i)>=1&&A.at(i)<=399) B.at(0)=true;
        if(A.at(i)>=400&&A.at(i)<=799) B.at(1)=true;
        if(A.at(i)>=800&&A.at(i)<=1199) B.at(2)=true;
        if(A.at(i)>=1200&&A.at(i)<=1599) B.at(3)=true;
        if(A.at(i)>=1600&&A.at(i)<=1999) B.at(4)=true;
        if(A.at(i)>=2000&&A.at(i)<=2399) B.at(5)=true;
        if(A.at(i)>=2400&&A.at(i)<=2799) B.at(6)=true;
        if(A.at(i)>=2800&&A.at(i)<=3199) B.at(7)=true;
        if(A.at(i)>=3200) count++;
    }
    for(int i=0; i<8; i++)
    {
        if(B.at(i))
        {
            min++;
        }
    }
    max=min+count;
    /*if(max>=8) max=8;*/
    if(min==0) min=1;
    cout << min << " " << max <<endl;
}