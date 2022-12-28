#include <bits/stdc++.h>
using namespace std;

//https://www.codechef.com/problems/KITCHENCOST

#define ll long long
#define vi vector<int>
#define vll vector<long long>

void solve() {
    int n; cin >> n;
    int x; cin >> x;

    vi fresh, cost; int temp;

    for(int i=0; i<n; i++){
        cin >> temp;
        fresh.push_back(temp);
    }
    for(int i=0; i<n; i++){
        cin >> temp;
        cost.push_back(temp);
    }

    //solving
    int ans = 0;
    for(int i=0; i<n; i++){
        if(fresh[i] >= x)
            ans += cost[i];
    }

    cout << ans << "\n";

}

int main() {
    int t; cin >> t;
    for(int i=0; i<t; i++)
        solve();
}