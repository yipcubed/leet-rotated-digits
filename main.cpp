#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

// https://leetcode.com/problems/rotated-digits/

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    // 0, 1, 8 -- same
    // 2 <--> 5
    // 6 <--> 9
    // 3, 4, 7 invalid

    int rotatedDigits(int N) {
        enum { Invalid = 0, Valid = 1, Good = 2 };
        //                          0      1     2       3        4       5    6       7       8      9
        static const vector<int> r{Valid, Valid, Good, Invalid, Invalid, Good, Good, Invalid, Valid, Good};
        vector<int> m(static_cast<unsigned long>(N + 1));
        int count = 0;
        for (int i = 0; i <= min(N, 9); ++i) {
            m[i] = r[i];
            if (r[i] == Good)
                ++count;
        }
        for (int i = 10; i <= N; ++i) {
            int rem = i % 10;
            int small = i / 10;
            if (m[rem] == Invalid || m[small] == Invalid)
                m[i] = Invalid;
            else if (m[rem] == Good || m[small] == Good) {
                m[i] = Good;
                ++count;
            } else {
                m[i] = Valid;
            }
        }
        return count;
    }
};

void test1() {

    cout << "4 ? " << Solution().rotatedDigits(10) << endl;
}

void test2() {

}

void test3() {

}