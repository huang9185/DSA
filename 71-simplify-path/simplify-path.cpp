class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        stringstream ss(path);
        string segment;
        
        // 1. Automatically split by '/'
        while (getline(ss, segment, '/')) {
            if (segment == "" || segment == ".") {
                continue; // Skip empty segments and current directory markers
            }
            if (segment == "..") {
                if (!s.empty()) s.pop(); // Go up a level
            } else {
                s.push(segment); // Push valid directory name
            }
        }
        
        // 2. Build the final path
        if (s.empty()) return "/";
        
        string res = "";
        while (!s.empty()) {
            res = "/" + s.top() + res;
            s.pop();
        }
        return res;
    }
};