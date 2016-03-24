#define VAM 1
#define KAN 2
#include<bits/stdc++.h>
using namespace std;

struct asd
{
    int node,weit;
};
list<struct asd>List[30005];

int color[30005];
long long besi=0,weight[30005];
struct asd var;

void DFS(int u)
{

    color[u]=1;
    for(list<struct asd>::iterator i=List[u].begin ();i!=List[u].end ();i++)
    {
        if(color[(*i).node]==0)
        {
            weight[(*i).node]=weight[u]+(*i).weit;
            if(weight[(*i).node]>besi)
            {
                besi=weight[(*i).node];
                var=*i;
            }
            DFS((*i).node);
        }
    }
    color[u]=2;

}

int main()
{
    int T;
    scanf("%d",&T);
    for(int tc=1;tc<=T;tc++)
    {
        int n, a,b,c=0;
        besi=0;
        memset(color,0,sizeof color);
        memset(weight,0,sizeof weight);
        scanf("%d",&n);
        for(int i=0;i<30005;i++)List[i].clear ();
        for(int i=1;i<n;i++)
        {

            struct asd lop,pol;
            scanf("%d%d%d",&a,&b,&c);
            lop.node=a;
            pol.node=b;
            lop.weit=c;
            pol.weit=c;
            List[a].push_back (pol);
            List[b].push_back (lop);
        }
        DFS(a);
        memset(color,0,sizeof color);
        memset(weight,0,sizeof weight);
        besi=0;
        DFS(var.node);
        printf("Case %d: %lld\n",tc,besi);

//        for(int i=0;i<5;i++)
//        {
//            cout<<weight[i]<<ends;
//        }







    }
    return 0;
}
