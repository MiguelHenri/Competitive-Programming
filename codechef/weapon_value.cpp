#include <bits/stdc++.h>
using namespace std;

//https://www.codechef.com/problems/SC31

#define ll long long
#define vi vector<int>
#define vll vector<long long>

void solve() {
    //reading input
    int n; cin >> n;
    vi weapons; string s;
    for(int i=0; i<n; i++){
        cin >> s;
        weapons.push_back(stoi(s, 0, 2));
    }
    int xo = weapons[0];
    for(int i=1; i<n; i++){
        xo = xo^weapons[i];
    }

    int ans = 0;
    while(xo>0){
        if(xo%2 == 1)
            ans++;

        xo /= 2;
    }

    cout << ans << "\n";
}

int main() {
    //treating tests
    int t; cin >> t;
    while(t--)
        solve();
}