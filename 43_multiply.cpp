#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.empty() || num2.empty())
            return "";
        int n = num1.length();
        int m = num2.length();
        if(num1.length() == 1 && num2.length() == 1)
            return to_string(int(num1[0]-48)*int(num2[0]-48));
        string A = num1.substr(0, n/2);
        string B = num1.substr(n/2, n-n/2);
        string C = num2.substr(0, m/2);
        string D = num2.substr(m/2, m-m/2);
        string AC = multiply(A, C);
        string AD = multiply(A, D);
        string BC = multiply(B, C);
        string BD = multiply(B, D);
        if(AC != "" && AC != "0")
            AC += string(n-n/2+m-m/2, '0');
        if(AD != "" && AD != "0")
            AD += string(n-n/2, '0');
        if(BC != "" && BC != "0")
            BC += string(m-m/2, '0');
        string s;
        int c = 0;
        int len = int(max({AC.length(), AD.length(), BC.length(), BD.length()}));
        for(int i = 1; i <= len; i++){
            if(i <= AC.length()){
                c += AC[AC.length()-i]-48;
            }
            if(i <= AD.length()){
                c += AD[AD.length()-i]-48;
            }
            if(i <= BC.length()){
                c += BC[BC.length()-i]-48;
            }
            if(i <= BD.length()){
                c += BD[BD.length()-i]-48;
            }
            s += char((c%10)+48);
            c /= 10;
        }
        if(c != 0){
            s += char((c%10)+48);
        }
        reverse(s.begin(), s.end());
        return s;
    }
};


int main(){
    string num1 = "9133";
    string num2 = "0";
    class Solution solution;
    cout << solution.multiply(num1, num2) << endl;
    return 0;
}

