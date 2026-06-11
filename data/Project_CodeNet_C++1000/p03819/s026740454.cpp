    #include <bits/stdc++.h>  
    using namespace std;  
    typedef long long ll;  
    const int N=3e5+20;  
    int n,m,c[N];  
    struct node{  
        int l,r,len;  
    }a[N];  
    bool cmp(node a,node b)  
    {  
        return a.len<b.len;  
    }  
    void update(int j,int k)  
    {  
        for(int i=j;i<=m;i+=(i&-i))  
            c[i]+=k;  
    }  
    int sum(int j)  
    {  
        int res=0;  
        for(int i=j;i>=1;i-=(i&-i))  
            res+=c[i];  
        return res;  
    }  
    int main()  
    {  
        while(cin>>n>>m)  
        {  
            memset(c,0,sizeof(c));//  
            for(int i=1;i<=n;i++)  
            {  
                scanf("%d%d",&a[i].l,&a[i].r);  
                a[i].len=a[i].r-a[i].l+1;  
            }  
            sort(a+1,a+n+1,cmp);  
            int k=1;  
            for(int d=1;d<=m;d++)  
            {  
                //O(m+nlogm)  
                for(;k<=n&&a[k].len<d;k++)//最多n次   
                {  
                    update(a[k].l,1);  
                    update(a[k].r+1,-1);//差分,[1..li..kd..ri,ri+1...m],树状数组统计前缀和   
                }  
                int ans=n-k+1;//区间长度>=d个数   
                //O(mlogm)  
                for(int e=d;e<=m;e+=d)  
                {  
                    ans+=sum(e);  
                }  
                cout<<ans<<endl;  
            }  
        }  
        return 0;  
    }  