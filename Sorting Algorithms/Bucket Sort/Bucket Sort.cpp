#include<bits/stdc++.h>

using namespace std;

void Bucket_sort(float ar[], int n)
{
    vector<float> b[n];
    int i,j,k=0;

    for(i=0; i<n; i++)
    {
        int bi = n*ar[i];
        b[bi].push_back(ar[i]);
    }

    for(i=0; i<n; i++)
    {
        sort(b[i].begin(), b[i].end());
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<b[i].size(); j++)
        {
            ar[k++]=b[i][j];
        }
    }
}

int main()
{
    float ar[] = {0.42, 0.65, 0.03, 0.49, 0.32, 0.15, 0.45, 0.38, 0.19, 0.78};

    int n = sizeof(ar)/sizeof(ar[0]);

    Bucket_sort(ar,n);

    for(int i = 0; i < n; i++)
    {
        cout<<ar[i]<<"  ";
    }
    cout<<endl;

    return 0;
}
