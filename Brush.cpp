
#include<bits/stdc++.h>
using namespace std;
int color[105],mat[105][105];
long long wei[105];
queue<int>Q;
void BFS(int s)
{

    color[s]=1;
    Q.push (s);
    wei[s]=0;
    while(!Q.empty ())
    {
        int u=Q.front ();
        Q.pop ();
        for(int i=0;i<=100 ;i++)
        {
            int w=mat[u][i];
            if(w!=-1)
            {
                if(wei[i]==-1)wei[i]=wei[u]+w;
                else
                {
                    if(wei[u]+w<wei[i])wei[i]=wei[u]+w;
                }

                if(color[i]==0)Q.push (i);
                color[i]=1;
            }

        }
        color[u]=2;


    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int tc=1;tc<=T;tc++)
    {
        int n,m,u,v,w,t;
        scanf("%d%d",&n,&m);
        memset(wei,-1,sizeof wei);
        memset(mat,-1,sizeof mat);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            if((mat[u][v]==-1 || w<mat[u][v]) && u!=v)
            {
                mat[u][v]=w;
                mat[v][u]=w;
            }
        }


        for(int i=0;i<n;i++)
        {
            memset(color,0,sizeof color);
            BFS(1);
        }
        if(wei[n]==-1)printf("Case %d: Impossible\n",tc);
        else printf("Case %d: %lld\n",tc,wei[n]);



    }
    return 0;
}
