# DP 

# 0-1 Knapsack 

### CODE:
```c++
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int p[] = {0,1,2,5,6};
    int wt[] = {0,2,3,4,5};
    int v[5][9];

    int m = 8, n = 4;

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

```

### SOURCE:
[Abdul Bari](https://www.youtube.com/watch?v=nLmhmB6NzcM&t=1s)  
[Abdul Bari2](https://www.youtube.com/watch?v=zRza99HPvkQ&t=22s)  

# LCS

### CODE:
```c++
#include<bits/stdc++.h>

using namespace std;

int lcs(string s1, string s2, int n, int m)
{
    if(n==0 || m==0){
        return 0;
    }
    if(s1[n-1]==s2[m-1]){
        return 1+lcs(s1,s2,n-1,m-1);
    }
    else {
        return max(lcs(s1,s2,n-1,m),lcs(s1,s2,n,m-1));
    }
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;

    int n = s1.size();
    int m = s2.size();

    cout<<lcs(s1,s2,n,m)<<endl;

    return 0;
}

```
### SOURCE:
[ApnaCollege](https://www.youtube.com/watch?v=Esx-TxF5PSo&t=453s)   

