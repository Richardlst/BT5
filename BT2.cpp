#include<bits/stdc++.h>
using namespace std;
void khoitao(int m, int n, char a[10][10])
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            a[i][j]='.';
        }
    }
}
void taomatran(int m,int n,int k, char a[10][10])
{
    khoitao(m, n, a);
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
    if(a[i][j]=='*') t=100;
    return t;
}
void print(int m, int n, char a[10][10])
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
void loang(char b[10][10], int x, int y, char a[10][10], int m, int n)
{
	if(b[x][y]!='.') return;
    int d = domin(x, y, a);
    if (d == 0) {
    b[x][y] = '_';
    for (int i = x - 1; i <= x + 1; i++) {
            for (int j = y - 1; j <= y + 1; j++) {
                if (i >= 0 && i < m && j >= 0 && j < n) {
                    loang(b, i, j, a, m, n);
                }
            }
        }
    }
    else {
    b[x][y] = char(d + '0');
    }
}

int dem(int m, int n, char b[10][10]){
    int cnt=0;
for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
        if(b[i][j]!='.') cnt++;
    }
}
return cnt;
}
int main()
{
    int m, n, k, x, y;
    char a[10][10], b[10][10];
    cin>>m>>n>>k;
    khoitao(m, n, b);
    taomatran(m, n, k, a);
    while(1)
    {
        cin>>x>>y;
        if(a[x][y]=='*')
        {
            cout<<"You are dead"<<endl;
            print(m, n, a);
            break;
        }
        else
        {
            loang(b, x, y, a, m, n);
            print(m,n,b);
            if(dem(m,n,b)==m*n-k)
            {
                cout<<"You win!";
                break;
            }
        }
    }
    return 0;
}

