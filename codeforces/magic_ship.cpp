#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pll pair<long long, long long>

int main()
{
    /*reading input*/
    pll o, d;
    cin >> o.first >> o.second >> d.first >> d.second;

    int n; cin >> n;

    char s[n];
    for(int i=0; i<n; i++)
        cin >> s[i];


    vll x_in_day(n+1, 0);
    vll y_in_day(n+1, 0);

    //calculating coordinates due to the wind factor in each day from 0 to n,
    //before reestarting the loop.
    for(int i=0; i<n; i++){
        x_in_day[i+1] = x_in_day[i];
        y_in_day[i+1] = y_in_day[i];
        if(s[i] == 'U') y_in_day[i+1]++;
        else if(s[i] == 'D') y_in_day[i+1]--;
        else if(s[i] == 'L') x_in_day[i+1]--;
        else x_in_day[i+1]++;
    }

    /*binary searching minimal number of days*/
    ll min_days = -1;
    ll right = n*(abs(o.first - d.first)+abs(o.second - d.second)); 
    ll left = 0; ll middle;
    while(right>=left){

        middle = (right+left)/2;

        ll full_cycles = middle/n;
        ll extra_days = middle%n;

        pll a;
        a.first = o.first + x_in_day[n]*full_cycles + x_in_day[extra_days];
        a.second = o.second + y_in_day[n]*full_cycles + y_in_day[extra_days];
        ll distance = abs(d.first - a.first) + abs(d.second - a.second); //manhattan distance

        if(distance <= middle){ //distance is smaller or equal number of days,
            min_days = middle;  //so, captain can get to the destination
            right = middle - 1;
        }

        else 
            left = middle + 1;
    }
    
    cout << min_days;

	return 0;
}
