#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& songs) { // size & the songs array
    int start {}, ans {};
    map<int, int> m;

    for(int end=0; end<n; end++) {
        if(m.find(songs[end]) == m.end()) { // if element not already in the array, add it
            m.insert({songs[end], end});
        } else {
            if(m[songs[end]] >= start) { // if already there, change the starting pointer
                start = m[songs[end]] + 1;
            }
            m[songs[end]] = end; // change the new index to the current element's index
        }
        ans = max(ans, end-start+1); // answer is the size of the maximum subarray
    }
    return ans;
}