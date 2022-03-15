#include <iostream>
#include <vector>
using namespace std;

string str[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>re;
        if(digits == ""){
            return re;
        }
        if(digits.length() == 1){
            for(auto c : str[digits[0]-50]){
                string s = "";
                s.insert(0, 1, c);
                re.push_back(s);
            }
            return re;
        }
        else{
            char str0 = digits[0];
            vector<string> vec(letterCombinations(digits.substr(1,digits.length()-1)));
            for(auto c : str[str0-50]){
                for(auto s:vec){
                    s.insert(0, 1, c);
                    re.push_back(s);
                }
            }
            return re;
        }
    }
};


int main(){
    class Solution solution;
    string s = "234";
    for(auto str: solution.letterCombinations(s)){
        cout << str <<endl;
    }
}