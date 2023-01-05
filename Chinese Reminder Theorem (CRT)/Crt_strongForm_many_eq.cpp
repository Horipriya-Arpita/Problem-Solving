
#include<bits/stdc++.h>

using namespace std;

struct xyg{
    int x;
    int y;
    int g;
};

xyg ext_euclid(int a, int b)
{
    xyg ans;
    if(b==0)
    {
        ans.x = 1;
        ans.y = 0;
        ans.g = a;
        return ans;
    }

    xyg sm_ans = ext_euclid(b,a%b);

    ans.x = sm_ans.y;
    ans.y = sm_ans.x - (a/b)*sm_ans.y;
    ans.g = sm_ans.g;

    return ans;
}

int crt_strong(int a[], int m[])
{
    int a1,a2,m1,m2,x,mod;
    a1 = a[0];
    m1 = m[0];

    for(int i = 1; i < 3; i++)
    {
        a2 = a[i];
        m2 = m[i];

        int g = __gcd(m1,m2);

        if(a1%g != a2%g){
            return -1;
        }

        xyg pq = ext_euclid(m1/g,m2/g);
        int p = pq.x;
        int q = pq.y;

        mod = (m1/g)*m2;

        x = (a1*(m2/g)*q + a2*(m1/g)*p) % mod;

        a1 = x;
        m1 = mod;
    }

    if (x < 0) x += mod; /** Result is not suppose to be negative*/
    return x;
}

int main()
{
    int a[] = {2, 2, 4};
    int m[] = {3, 6, 5};

    int x = crt_strong(a,m);

    cout<<x<<endl;

    return 0;
}

