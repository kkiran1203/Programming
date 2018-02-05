Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<int> end(n, 0);
        vector<int> start(n, 0);
        for( int i=0; i<n; i++ ) {
            start[i] = intervals[i].start;
            end[i] = intervals[i].end;
        }
        sort(end.begin(), end.end());
        sort(start.begin(), start.end());
        int res = 0;
        int i=0;
        int j=0;
        int ans = 0;
        while( i<n && j<n ) {
            if( start[i] <= end[j] ) {
                res++;
                ans = max( ans, res );
                i++;
            } else {
                res--;
                j++;
            }
        }
        return ans;
    }
};