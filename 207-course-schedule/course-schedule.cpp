class Solution {
public:
// some comments
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses, 0);
        vector<vector<int>> adj(numCourses, vector<int>{});
        for (auto pre: prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            indeg[pre[0]]++;
        }
        queue<int> courses;
        for (int i = 0; i < indeg.size(); ++i) {
            if (indeg[i] == 0) courses.push(i);
        }
        int coursesPoped = 0;
        while (!courses.empty()) {
            int course = courses.front();
            courses.pop();
            coursesPoped++;
            for (int c : adj[course]) {
                indeg[c]--;
                if (indeg[c] == 0) courses.push(c);
            }
            adj[course].clear();
        }
        return coursesPoped == numCourses;
    }
};