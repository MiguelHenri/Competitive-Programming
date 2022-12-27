#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/contest/1731/problem/B

#define ll long long
#define vi vector<int>
#define vll vector<long long>

ll m = 1000000007;

ll aux(ll a, ll b)
{
    ll ans=1;
    while(b>0){
        if((b%2)==1){
            ans=(ans*a)%m;
        }
        a=(a*a)%m;
        b/=2;
    }
    return ans;
}
ll ss(ll n)
{
    ll ans=(((n*(n+1))%m)*(2*n+1)%m)%m;;
    ans=(ans*aux(6, m-2))%m;
    
    return ans;
}
ll sl(ll n)
{
    ll ans=(n*(n+1))%m;
    ans=(ans*aux(2, m-2))%m;
    
    return ans;
}
int main()
{
    ll tests, n, ans, i;
    
    cin>>tests;
    
    while(tests--)
    {
        cin>>n;
        
        ans=0;
        
        ans = (ans+ss(n))%m;
        ans = (ans+ss(n-1))%m;
        ans = (ans+sl(n-1))%m;
        ans = (ans*2022)%m;
        
        cout << ans << "\n";
        
    }
    
}