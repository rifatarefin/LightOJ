
#include<bits/stdc++.h>
using namespace std;
int color[500],wei[500],mat[500][500];
queue<int>Q;
void BFS(int s)
{

    color[s]=1;
    wei[s]=0;
    Q.push (s);
    while(!Q.empty ())
    {
        int u=Q.front ();
        Q.pop ();
        for(int i=0;i<500 ;i++)
        {
            int w=mat[u][i];
            if(w!=0 )
            {
                int p;
                if(w>wei[u])p=w;
                else p=wei[u];
                if(wei[i]==0)wei[i]=p;
                else
                {
                    if(p<wei[i])wei[i]=p;
                }
                if(color[i]==0)Q.push (i);
                color[i]=1;
            }
        }
        color[u]=2;
//        for(int i=0;i<5;i++)
//            cout<<wei[i]<<ends;
//        cout<<endl;

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
        memset(mat,0,sizeof mat);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            if(mat[u][v]==0 || w<mat[u][v])
            {
                mat[u][v]=w;
                mat[v][u]=w;
            }
        }
        scanf("%d",&t);
        printf("Case %d:\n",tc);
        memset(wei,0,sizeof wei);
        for(int i=0;i*i<n;i++)
        {
            memset(color,0,sizeof color);
            BFS(t);
        }

        for(int i=0;i<n;i++)
        {
            if(i==t)printf("0\n");
            else
            {
                if(wei[i])
                    printf("%d\n",wei[i]);
                else printf("Impossible\n");
            }
        }

    }
    return 0;
}
