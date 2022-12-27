#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>

int main()
{
    //number of tests
    int tests; cin >> tests;
    //solving the tests
    for(int i=1; i<=tests; i++){
        //reading input
        string s; cin >> s;
        int k; cin >> k;

        //solving
        //s.size - k + 1 possible flips
        //flipping leftmost '-' pancake
        int ans = 0; //answer
        vi obsolete_flips(s.size()+1, 0);

        int flipped;
        for(int j=0; j<(s.size()-k+1); j++){
            obsolete_flips[j] += obsolete_flips[j-1];
            flipped = ans - obsolete_flips[j];
            if((s[j] == '+' && flipped%2 == 1) || (s[j] == '-' && flipped%2 == 0)){
                //flips
                ans += 1;
                if(j < s.size()-k)
                    obsolete_flips[j+k] += 1;
            }
        }

        //checking if all are on happy side (+)
        for(int j=s.size()-k+1; j<=s.size(); j++){
            obsolete_flips[j] += obsolete_flips[j-1];
            flipped = ans - obsolete_flips[j];
            if((s[j] == '+' && flipped%2 == 1) || (s[j] == '-' && flipped%2 == 0)){
                ans = -1;
            }
        }

        if(ans == -1)
            cout << "Case #" << i << ": IMPOSSIBLE\n";
        else
            cout << "Case #" << i << ": " << ans << "\n";
    }
}