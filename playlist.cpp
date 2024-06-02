#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& songs) { // Size & the songs array
    int start {}, ans {};
    map<int, int> m;

    for(int end=0; end<n; end++) {
        if(m.find(songs[end]) == m.end()) {
            m.insert({songs[end], end});
        } else {
            if(m[songs[end]] >= start) {
                start = m[songs[end]] + 1;
            }
            m[songs[end]] = end;
        }
        ans = max(ans, end-start+1);
    }
    return ans;
}