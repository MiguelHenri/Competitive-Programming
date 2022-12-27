#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/contest/1731/problem/A

#define ll long long
#define vi vector<int>
#define vll vector<long long>

void solve(int t){
    int n; cin >> n;
    vll v; ll temp;
    for(int i=0; i<n; i++){
        cin >> temp;
        v.push_back(temp);
    }

    ll ans = 1;

    for(int i=0; i<n; i++){
        ans *= v[i];
    }

    ans += n-1;

    cout << ans*2022 << "\n";
}

int main()
{
    int tests; cin >> tests;
    for(int i=1; i<=tests; i++){
        solve(i);
    }
}