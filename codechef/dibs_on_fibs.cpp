#include <bits/stdc++.h>
using namespace std;

//https://www.codechef.com/problems/DBFB

#define ll long long
#define vi vector<int>
#define vll vector<long long>

ll mod = 1000000007;

void solve(){
    int n, m;
    cin >> m >> n;

    ll suma = 0, sumb = 0, ans = -1;

    for(int i=0; i<m; i++){
        int temp; cin >> temp;
        suma = (suma+temp)%mod;
    }
    suma = (suma*m)%mod;

    for(int i=0; i<m; i++){
        int temp; cin >> temp;
        sumb = (sumb+temp)%mod;
    }
    sumb = (sumb*m)%mod;

    if(n==1)
        cout << suma << "\n";
    else if(n==2)
        cout << sumb << "\n";
    else{
        for(int i=3; i<=n; i++){
            ans = (suma+sumb)%mod;
            suma = sumb;
            sumb = ans;
        }
        cout << ans << "\n";
    }
}

int main(){
    int t; cin >> t;
    while(t--)
        solve();
}