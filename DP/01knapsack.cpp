#include<bits/stdc++.h>

using namespace std;

int main()
{
    int p[] = {60,100,150};//{0,1,2,5,6};
    int wt[] = {15,30,45};//{0,2,3,4,5};
    int v[4][51];//v[5][9];

    int m=50,n=3;//m = 8, n = 4;

    for(int i=0; i<=n; i++){
        for(int w=0; w<=m; w++)
        {
            if(i==0 || w==0){
                v[i][w]=0;
            }
            else if(wt[i]<=w){
                v[i][w] = max(v[i-1][w], v[i-1][w-wt[i]]+p[i]);
            }
            else{
                v[i][w] = v[i-1][w];
            }
        }
    }

    cout<<v[n][m]<<endl;

    return 0;
}
