#include<bits/stdc++.h>
using namespace std;
int color[100];
queue<int>Q;
list<int >List[100];
int* BFS(int s)
{

    int *weit=(int*)malloc(100*sizeof (int));
    for(int i=0;i<100;i++)weit[i]=-1;
    color[s]=1;
    Q.push (s);
    weit[s]=0;
    while(!Q.empty ())
    {
        int u=Q.front ();
        Q.pop ();
        for(list<int>::iterator it=List[u].begin ();it!=List[u].end();it++)
        {
            if(color[*it]==0)
            {
                color[*it]=1;
                weit[*it]=weit[u]+1;
                Q.push(*it);
            }
        }
        color[u]=2;


    }
     return weit;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int tc=1;tc<=T;tc++)
    {
        int n,m,u,v,s,d,*t1,*t2,xam=0;
        scanf("%d%d",&n,&m);
        for(int i=0;i<100;i++)List[i].clear ();

        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            List[u].push_back (v);
            List[v].push_back (u);

        }
        scanf("%d%d",&s,&d);
        memset(color,0,sizeof color);
        t1=BFS(s);
        memset(color,0,sizeof color);
        t2=BFS(d);
        for(int i=0;i<n;i++)
        {
            if((*(t1+i)+*(t2+i))>xam)xam=*(t1+i)+*(t2+i);
        }
        printf("Case %d: %d\n",tc,xam);





    }
    return 0;
}

