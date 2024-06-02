#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> q;

    for(int i=0, n=nums.size(); i <n; i++) {
        if(!q.empty() && q.front() <= i-k) { // remove elements that the window no longer covers
            q.pop_front();
        }
        while(!q.empty() && nums[q.back()] <= nums[i]) { // removes elements from the window that are smaller than the current element that are in the back
            q.pop_back();
        }
        q.push_back(i);

        if(i >= k-1) { // the maximum is at the front, so we take that value
            result.push_back(nums[q.front()]);
        }
    }
    return result;
}