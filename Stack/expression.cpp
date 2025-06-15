//2415..
#include <iostream>
#include <stack>
#include <cctype>
#include <string>
#include <cmath>
using namespace std;

// Function to get precedence of operator
int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

// Check if operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix;

    for(char ch : infix) {
        if(isalnum(ch)) {
            postfix += ch;
        } else if(ch == '(') {
            st.push(ch);
        } else if(ch == ')') {
            while(!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop(); // remove '('
        } else if(isOperator(ch)) {
            while(!st.empty() && precedence(st.top()) >= precedence(ch)) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while(!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

// Evaluate postfix expression (only single-digit values)
int evaluatePostfix(string postfix) {
    stack<int> st;
    for(char ch : postfix) {
        if(isdigit(ch)) {
            st.push(ch - '0');
        } else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            switch(ch) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
                case '^': st.push(pow(a, b)); break;
            }
        }
    }
    return st.top();
}

// Main program
int main() {
    int choice;
    string expression;

    cout << "=== Expression Tool ===\n";
    cout << "1. Convert Infix to Postfix\n";
    cout << "2. Evaluate Postfix Expression\n";
    cout << "3. Both Infix to Postfix & Evaluate\n";
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    cin.ignore();  // clear input buffer
    cout << "\nEnter Expression: ";
    getline(cin, expression);

    if(choice == 1) {
        string postfix = infixToPostfix(expression);
        cout << "Postfix: " << postfix << endl;
    }
    else if(choice == 2) {
        int result = evaluatePostfix(expression);
        cout << "Result: " << result << endl;
    }
    else if(choice == 3) {
        string postfix = infixToPostfix(expression);
        int result = evaluatePostfix(postfix);
        cout << "Postfix: " << postfix << endl;
        cout << "Result: " << result << endl;
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
