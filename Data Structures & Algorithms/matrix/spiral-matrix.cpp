class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        res.reserve(m*n);
        // right left up down
        vector<bool> dir{true,false, false, false};
        res.push_back(matrix[0][0]);
        matrix[0][0] = 101;
        // mark visited as 101
        // check boundary
        int nexti = 0, nextj = 0;
        int steps = 1;
        while(steps != m*n) {
            if (dir[0]) {
                nextj+=1;
                if (nextj == n || matrix[nexti][nextj] == 101) {
                    dir[0] = false;
                    dir[3] = true;
                    nextj -=1;
                    continue;
                }
            } else if (dir[1]) {
                nextj -= 1;
                if (nextj < 0  || matrix[nexti][nextj] == 101) {
                    dir[1] = false;
                    dir[2] = true;
                    nextj += 1;
                    continue;
                }
            }
            else if (dir[2]) {
                nexti -=1;
                if (nexti < 0 || matrix[nexti][nextj] == 101) {
                    dir[2] = false;
                    dir[0] = true;
                    nexti += 1;
                    continue;
                }
            }
            else {
                nexti += 1;
                if (nexti == m || matrix[nexti][nextj] == 101) {
                    dir[3] = false;
                    dir[1] = true;
                    nexti -= 1;
                    continue;
                }
            } 
            res.push_back(matrix[nexti][nextj]);
            matrix[nexti][nextj] = 101;
            ++steps;
        }
        return res;
    }
};

