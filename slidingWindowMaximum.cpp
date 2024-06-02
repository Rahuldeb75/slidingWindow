#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> q;

    for(int i=0, n=nums.size(); i <n; i++) {
        if(!q.empty() && q.front() <= i-k) {
            q.pop_front();
        }
        while(!q.empty() && nums[q.back()] <= nums[i]) {
            q.pop_back();
        }
        q.push_back(i);

        if(i >= k-1) {
            result.push_back(nums[q.front()]);
        }
    }
    return result;
}