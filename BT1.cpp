#include<bits/stdc++.h>
using namespace std;
void khoitao(int m, int n, int k, char a[10][10])
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            a[i][j]='.';
        }
    }
}
void taomatran(int m,int n,int k, char a[][10])
{
    khoitao(m, n,k, a);
    srand(time(0));
    for(int i=0; i<k; i++)
    {
        int p=rand()%m;
        int q=rand()%n;
        a[p][q]='*';
    }
}
int domin(int i, int j, char a[10][10])
{
    int t=0;
    for(int q=i-1; q<=i+1; q++)
    {
        for(int k=j-1; k<=j+1; k++)
        {
            if(q!=i||k!=j&&q>=0&&k>=0)
            {
                if(a[q][k]=='*')  t++;
            }
        }
    }
    return t;
}
void print(int m, int n, char a[][10])
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void print2(int m, int n, char b[][10], int x, int y, char a[][10])
{
    b[x][y]=char(domin(x, y, a)+'0');
    print(m, n, b);
}
int main()
{
    int m, n, k, x, y, l=0;
    char a[10][10], b[10][10];
    cin>>m>>n>>k;
    khoitao(m, n, k, b);
    taomatran(m, n, k, a);
    while(1)
    {
        cin>>x>>y;
        l++;
        if(a[x][y]=='*')
        {
            cout<<"You are dead"<<endl;
            print(m, n, a);
            break;
        }
        else
        {
            print2(m, n, b, x, y, a);
            if(l==m*n-k)
            {
                cout<<"You win!";
                break;
            }
        }
    }
    return 0;
}
