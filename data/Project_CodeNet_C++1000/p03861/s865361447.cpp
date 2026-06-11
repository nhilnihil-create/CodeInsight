    #include <bits/stdc++.h>
    using namespace std;
    int main() 
    {
        long long int a,b,x,temp,out;
        cin>>a>>b>>x;
        temp=a/x;
        if(a%x==0)
        {
            a=temp;
        }
        else
            a=temp+1;
        b=b/x;
        out=b-a+1;
        cout<<out<<endl;
        return 0;
    }