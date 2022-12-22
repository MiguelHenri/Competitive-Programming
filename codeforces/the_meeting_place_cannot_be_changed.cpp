#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>

bool is_time_enough(vi pos, vi vel, double time, int n) {
    double leftmostright = INT_MAX; double rightmostleft = INT_MIN;
    for(int i=0; i<n; i++){
        leftmostright = min(leftmostright, pos[i] + (double)(vel[i]*time));
    }
    for(int i=0; i<n; i++){
        rightmostleft = max(rightmostleft, pos[i] - (double)(vel[i]*time));
    }
    return rightmostleft <= leftmostright;
}

int main()
{
    /*reading input*/
    int n;
    cin >> n;
    
    vi pos, vel;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        pos.push_back(temp);
    }
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        vel.push_back(temp);
    }

    /*binary searching approximate time*/
    double left = 0.0; double right = 1e9; double middle;
    while(abs(right-left)>1e-6){
        middle = (left+right)/2;
        
        if(is_time_enough(pos, vel, middle, n))
            right = middle;
        else
            left = middle;
    }

    printf("%.9lf", middle);
}
