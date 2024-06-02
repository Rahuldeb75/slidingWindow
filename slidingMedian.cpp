#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> arr;
multiset<int> low;
multiset<int> high;
 
void ins(int val) {
    int median = *low.rbegin();

    if(median < val) { // if median less than the value, put the value in high
        high.insert(val);
        if(high.size() > k/2) { // if high too big, put it in low
            low.insert(*high.begin()); 
            high.erase(high.find(*high.begin()));
        }
    } else {
        low.insert(val); 
        if(low.size() > (k+1)/2) {
            high.insert(*low.rbegin());
            low.erase(low.find(*low.rbegin()));
        }
    }
}

void er(int val) {
    if(high.find(val) != high.end()) { // if in high, erase from high
        high.erase(high.find(val));
    } else {
        low.erase(low.find(val));
    }
    if(low.empty()) { // if low is empty, get element from high
        low.insert(*high.begin());
        high.erase(high.find(*high.begin()));
    }
}

int main() {
    cin >> n >> k;
    arr.resize(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    // find max for the first window because future loops expect some data to already be on the low and high sets
    low.insert(arr[0]);
    for(int i=1; i<k; i++) ins(arr[i]);
    cout << *low.rbegin() << " ";

    for(int i=k; i<n; i++) {
        if(k == 1) { // insert before erasing to make sure that the set with the lower values is not empty.
            ins(arr[i]);
            er(arr[i-k]);
        } else {
            er(arr[i-k]);
            ins(arr[i]);
        }
        cout << *low.rbegin() << " ";
    }
    cout << endl;
}