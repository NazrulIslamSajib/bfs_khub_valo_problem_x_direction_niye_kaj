#include<bits/stdc++.h>
using namespace std;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dx1[] = {1,-1,-1,1};
int dy1[] = {1,1,-1,-1};
//int dx1[] = {-1, -1, -1, 0, 0, 1, 1, 1};
//int dy1[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int vis1[100][100];
int vis2[100][100];
bool isvalid(int a,int b)
{
    return a<=8 && a>=1 && b<=8 && b>=1;
}
int main()
{
    int tt;
   // cin>>tt;
   tt=1;
    while(tt--)
    {
     int x1,y1,x2,y2,i,j;
     cin>>x1>>y1>>x2>>y2;
     queue<pair<int,int>>q1,q2;
     pair<int,int>s1,d,s2;
     for(i=1;i<=8;i++)
     {
           for(j=1;j<=8;j++)
           {
               vis1[i][j]=-1;
               vis2[i][j]=-1;
           }
     }
     s1.first=x1;
     s1.second=y1;
     s2.first=x1;
     s2.second=y1;
     d.first=x2;
     d.second=y2;
     vis1[s1.first][s1.second]=0;
     vis2[s2.first][s2.second]=0;
     q1.push(s1);
     while(!q1.empty())
     {
        pair<int,int>u;
        u=q1.front();
        q1.pop();
        for(int k=1;k<=8;k++)
        {
            pair<int,int>v;
            v={u.first+dx[k-1],u.second+dy[k-1]};
            if(vis1[v.first][v.second]==-1 && isvalid(v.first,v.second))
            {
                vis1[v.first][v.second]=vis1[u.first][u.second]+1;
                q1.push(v);
            }
        }
     }
     /// for bishop
     q2.push(s2);
     while(!q2.empty())
     {
        pair<int,int>u;
        u=q2.front();
        q2.pop();
        for(int k=1;k<=4;k++)
        {
            pair<int,int>v;
            v={u.first+dx1[k-1],u.second+dy1[k-1]};
            if(vis2[v.first][v.second]==-1 && isvalid(v.first,v.second))
            {
                vis2[v.first][v.second]=vis2[u.first][u.second]+1;
                q2.push(v);
            }
        }
     }
     /*

     for(i=0;i<8;i++)
     {
         for(j=0;j<8;j++)
         {
             cout<<vis2[i][j]<<" ";
         }
         cout<<endl;
     }
     */
     if(x1==x2 || y1==y2)
     {
         cout<<1<<" ";
     }
     else
     {
         cout<<2<<" ";
     }
     if(vis2[d.first][d.second]!=-1)
     {
        // if(abs(y1-y2)<vis2[d.first][d.second] && x1!=x2)
         if(abs(x1-x2)==abs(y1-y2))
         {
             cout<<1<<" ";
         }
         else
         {
             cout<<2<<" ";
         }
     }
     else
     {
         cout<<0<<" ";
     }
     cout<<vis1[d.first][d.second]<<endl;

    }
    return 0;

}

