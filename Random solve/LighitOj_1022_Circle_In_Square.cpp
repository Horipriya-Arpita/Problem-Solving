/*
Problem Link;
https://lightoj.com/problem/circle-in-square
*/
#include<bits/stdc++.h>

using namespace std;

const double pi = 2*acos(0.0);
int cs;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        cs++;
        double r,p,ans;
        scanf("%lf",&r);
        p = 4 - pi;
        ans = p*r*r;

        printf("Case %d: %.2lf\n",cs,ans);
    }
    return 0;
}

/*
Here, a = 2*r; which is the length of any side of the square.
So the answer is:
ans = a^2 - pi*r^2
    = (2*r)^2 - pi*r^2
    = (4-pi)*r*r;
    = p * r * r ; where p = 4 - pi.
*/
