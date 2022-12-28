#include <bits/stdc++.h>
using namespace std;

//https://www.codechef.com/problems/MUSICHAIR

#define ll long long
#define vi vector<int>
#define vll vector<long long>

void solve() {
    //reading input
    int n; cin >> n;

    int ans = 0;

    //remainder 1
    int x = n-1;

    for(int i=1; i*i<=x; i++){ //from 1 to sqrt(x)
        if(x%i == 0){ //divisor
            ans++;
            if(i * i != x) //another divisor > sqrt(x) / i*divisor = x
                ans++;
        }
    }

    cout << ans << "\n";
    //this way answer keeps O(sqrt(n))
}

int main() {
    //treating tests
    int t; cin >> t;
    while(t--)
        solve();
}