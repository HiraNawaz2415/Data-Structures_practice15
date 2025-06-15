#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>
#include <cctype>
#include <vector>
using namespace std;

int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool isHigher(char op1, char op2) {
    return precedence(op1) >= precedence(op2);
}

vector<string> tokenize(string expr) {
    vector<string> tokens;
    string num;
    for (char ch : expr) {
        if (isdigit(ch) || ch == '.') {
            num += ch;
        } else {
            if (!num.empty()) {
                tokens.push_back(num);
                num.clear();
            }
            if (!isspace(ch)) {
                tokens.push_back(string(1, ch));
            }
        }
    }
    if (!num.empty()) tokens.push_back(num);
    return tokens;
}

string infixToPostfix(string infix) {
    vector<string> tokens = tokenize(infix);
    stack<string> st;
    string postfix;
    for (string token : tokens) {
        if (isdigit(token[0]) || token[0] == '.') {
            postfix += token + " ";
        } else if (token == "(") {
            st.push(token);
        } else if (token == ")") {
            while (!st.empty() && st.top() != "(") {
                postfix += st.top() + " ";
                st.pop();
            }
            if (!st.empty()) st.pop();
        } else if (isOperator(token[0])) {
            while (!st.empty() && isOperator(st.top()[0]) && isHigher(st.top()[0], token[0])) {
                postfix += st.top() + " ";
                st.pop();
            }
            st.push(token);
        }
    }
    while (!st.empty()) {
        postfix += st.top() + " ";
        st.pop();
    }
    return postfix;
}

float evaluatePostfix(string postfix) {
    vector<string> tokens = tokenize(postfix);
    stack<float> st;
    for (string token : tokens) {
        if (isdigit(token[0]) || token[0] == '.') {
            st.push(stof(token));
        } else {
            float b = st.top(); st.pop();
            float a = st.top(); st.pop();
            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else if (token == "/") st.push(a / b);
            else if (token == "^") st.push(pow(a, b));
        }
    }
    return st.top();
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    for (auto &ch : infix) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }
    string revPostfix = infixToPostfix(infix);
    vector<string> revTokens = tokenize(revPostfix);
    reverse(revTokens.begin(), revTokens.end());
    string prefix;
    for (string s : revTokens) prefix += s + " ";
    return prefix;
}

bool validateExpression(string expr) {
    int balance = 0;
    for (char ch : expr) {
        if (ch == '(') balance++;
        else if (ch == ')') balance--;
        if (balance < 0) return false;
    }
    return balance == 0;
}

int main() {
    int choice;
    string expression;

    do {
        cout << "\n=== Expression Menu ===" << endl;
        cout << "1. Convert Infix to Postfix" << endl;
        cout << "2. Evaluate Postfix Expression" << endl;
        cout << "3. Convert Infix to Prefix" << endl;
        cout << "4. Convert & Evaluate Infix Expression" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice >= 1 && choice <= 4) {
            cout << "\nEnter expression: ";
            getline(cin, expression);

            if (!validateExpression(expression)) {
                cout << "❌ Invalid expression (unbalanced parentheses).\n";
                continue;
            }
        }

        switch (choice) {
            case 1:
                cout << "Postfix: " << infixToPostfix(expression) << endl;
                break;
            case 2:
                cout << "Result: " << evaluatePostfix(expression) << endl;
                break;
            case 3:
                cout << "Prefix: " << infixToPrefix(expression) << endl;
                break;
            case 4:
                {
                    string postfix = infixToPostfix(expression);
                    float result = evaluatePostfix(postfix);
                    cout << "Postfix: " << postfix << endl;
                    cout << "Result: " << result << endl;
                }
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "!Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
