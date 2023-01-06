#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/contest/1779/problem/B

#define ll long long
#define vi vector<int>
#define vll vector<long long>

void solve(){
    //reading input
    int n; cin >> n;

    //solve
    if(n%2 == 0){
        cout << "YES\n";
        for(int i=0; i<n/2; i++)
            cout << "1 -1 ";
        cout << "\n";
    }
    else if(n == 3)
        cout << "NO\n";
    else{
        cout << "YES\n";
        int aux = n/2;
        for(int i=0; i<n/2; i++)
            cout << 1-aux << " " << aux << " ";
        cout << 1-aux << "\n";
    }
}

int main(){
    int t; cin >> t;
    while(t--)
        solve();
}