class Solution {
public:
    string longestCommonPrefix(vector<string>  &strs) {
        if (strs.size() == 0) return "";
        std::string prefix = strs[0];
 
        for (int i = 1; i < strs.size(); ++i) {
          std::string s = strs[i];
          if (s.size() == 0 || prefix == "") return "";
          prefix = prefix.substr(0, std::min(prefix.size(), s.size()) );
            
            for (int k = 0; k < s.size() && k < prefix.size(); ++k) {
                if (s[k] != prefix[k]) {
                    prefix = prefix.substr(0, k);
                    break;
                }
            }
        }
        return prefix;
    }
};