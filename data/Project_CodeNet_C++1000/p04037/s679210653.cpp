    #include <bits/stdc++.h>  
    using namespace std;  
    inline int read()  
    {  
        int x=0;char ch=getchar();  
        while(ch>'9'||ch<'0')ch=getchar();  
        while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();  
        return x;  
    }  
    int n,a[200010],t;  
    int main()  
    {  
        n=read();  
        for(int i=1;i<=n;i++)  
        {  
            a[i]=read();      
        }     
        sort(a+1,a+n+1,greater<int>());  
        for(;a[t]>=t;t++);  
        t--;  
        if((a[t]-t)%2==0)  
        {  
            int j=0;  
            for(;a[t+j]>=t;j++);  
            if(j%2)  
            {  
                cout<<"Second"<<endl;  
                return 0;  
            }  
        }  
        cout<<"First"<<endl;  
        return 0;  
    }  