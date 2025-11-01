#include <iostream>
#include <stack>
#include <string>
using namespace std;
string isBalanced(string s) {
    stack<char> st;
    for(char c : s) {
        if(c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if(st.empty())
                return "NO";

            char top = st.top();
            st.pop();

            if((c == ')' && top != '(') ||
               (c == '}' && top != '{') ||
               (c == ']' && top != '['))
                return "NO";
        }
    }
    return st.empty() ? "YES" : "NO";
}
int main() {
    int n;
    cin >> n;   // number of test cases
    while(n--) {
        string s;
        cin >> s;
        cout << isBalanced(s) << endl;
    }

    return 0;
}
