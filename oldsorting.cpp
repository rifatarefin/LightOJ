#include<bits/stdc++.h>
using namespace std;

int main()
{

    int T;
    ifstream fin;
    fin.open ("example.txt");
    cin>>T;
    for(int tc=1;tc<=T;tc++)
    {
        int n;
        cin>>n;
        int a[n+1],x[n+1];
        for(int i=1;i<=n;i++)
        {
            int b;
            cin>>b;
            x[i]=b;
            a[b]=i;

        }
        clock_t tStart = clock();
        int cnc=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=i)
            {
                cnc++;
                int t=x[i],t2=a[i];
                x[a[i]]=x[i];
                x[i]=i;
                a[t]=t2;
                a[i]=i;


            }
        }
        for(int i=0;i<1000000000;i++);

        cout<<"Case "<<tc<<": "<<cnc<<endl;
            printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    }

    fin.close();
    return 0;

}




