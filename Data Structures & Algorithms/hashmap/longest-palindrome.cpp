class Solution {
public:
// assume there can be the same words
    int longestPalindrome(vector<string>& words) {
        // intuition: sort each word in some way
        // if word itself is palindrome (can be in the middle of palindrome or by itself)
        unordered_set<string> isPal;
        unordered_map<string, int> exist;
        int numHasReverse = 0;
        // reverse of the word is also a word
        // reverse of the word 
        for (string word : words) {
            string copy = word;
            reverse(copy.begin(), copy.end());
            if (copy == word) {
                if (isPal.find(copy) != isPal.end()) {
                    isPal.erase(copy);
                    numHasReverse++;
                }
                else isPal.insert(word);
            }
            else if (exist.find(copy) != exist.end()) {
                exist[copy]--;
                if (exist[copy] == 0) exist.erase(copy);
                numHasReverse++;
            } else exist[word]++;
        }
        return numHasReverse*4 + (isPal.empty() ? 0 : 2);
    }
};

