class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        // record line start as words index
        // go through each word, get string length, get so far string length total
        // if total > maxWidth, compute line so far, total = 0
        // calculate remaining space / (end - start)
        // if n of i ... j, first i+1, rest 
        vector<string> res;
        int start = 0;
        int total = words[0].size();
        for (int n = 1; n < size(words); ++n) {
            if (total + words[n].size() + (n-start) > maxWidth) {
                string line;
                // calculate line from start to n-1
                // each non-ending word needs a space behind
                int remainspaces = maxWidth - total - (n-1 - start);
                int i = start;
                while (i < n-1) {
                    line += words[i];
                    int gaps = n-1-i;
                    int curspace = n-1 == i ? remainspaces-1 : (remainspaces + gaps - 1) / gaps;
                    line.append(curspace+1, ' ');
                    remainspaces -= curspace;
                    i++;
                }
                line += words[i];
                line.append(remainspaces, ' ');
                start = n;
                total = words[n].size();
                res.push_back(line);
            } else {
                total += words[n].size();
            }
        }
        // compute last line
        string line;
        int spaces = maxWidth - total;
        while (start != size(words)) {
            line += words[start++];
            if (spaces > 0) {
                line += ' ';
                spaces--;
            } else {
                cout << spaces << endl;
            }
        }
        if (spaces >= 0) line.append(spaces, ' ');
        res.push_back(line);
        return res;
    }
};