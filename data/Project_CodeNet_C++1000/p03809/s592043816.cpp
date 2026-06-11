        #include <bits/stdc++.h>
        using namespace std;
        const int maxn=1e5+10,mod=1e9+7;
        int n,m,k,t,a[maxn],rt;
        vector<int>e[maxn];
        bool flag=true;
        long long dfs(int x,int y=0)
        {
            if(!flag)return -1;
            if(e[x].size()==1)return a[x];
            long long sum=0;
            vector<long long>tmp;
            for(int i=0;i<e[x].size();i++)
            {
                int z=e[x][i];
                if(z==y)continue;
                long long j=dfs(z,x);
                if(j>a[x])
               {
                    flag=false;
                    return -1;
               }
                if(j==-1)return -1;
                tmp.push_back(j);
                sum+=j;
            }
            long long delta=(sum-a[x]),ans=sum-2*delta;
            if( ans <0 || delta <0)
            {
                flag=false;
                return -1;
            }
            sort(tmp.begin(),tmp.end());
            int pos=tmp.size()-1;
            if(x==rt&&ans>0)
            {
                flag=false;
            }
            return ans;
        }
        int main(){
            int i,j;
            scanf("%d",&n);
            for(i=1;i<=n;i++)scanf("%d",&a[i]);
            for(i=1;i<n;i++)
            {
                int x,y;
                scanf("%d%d",&x,&y);
                e[x].push_back(y);
                e[y].push_back(x);
            }
            if(n==2)
            {
                if(a[1]==a[2])puts("YES");
                else puts("NO");
                return 0;
            }
            for(i=1;i<=n;i++)if(e[i].size()>1)
            {
                rt=i;
                dfs(rt);
                break;
            }
            puts(flag?"YES":"NO");
            return 0;
        }