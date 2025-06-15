## What is an Expression in DSA?
An expression is a combination of operands (like numbers or variables) and operators (like +, -, *, /) that computes a value.
## Types of Expressions:
| Type        | Example | Description                                         |
| ----------- | ------- | --------------------------------------------------- |
| **Infix**   | `A + B` | Operator is **between** operands (normal human way) |
| **Prefix**  | `+ A B` | Operator is **before** operands                     |
| **Postfix** | `A B +` | Operator is **after** operands                      |

---
## Why Convert Expressions?
➡Infix is hard for computers to evaluate directly due to operator precedence and parentheses.

➡That's why we convert infix → postfix or prefix for easy evaluation using stack.

---
## Expression Conversion
### 1. Infix to Postfix
Use stack to:

- Push operators and (.
- Output operands immediately.
- Pop on encountering ) or lower precedence.
- Infix:    A + B * C
- Postfix:  A B C * +


---
### 2. Infix to Prefix
- Reverse the expression → convert to postfix → reverse result
- Infix:    A + B
- Prefix:   + A B

---
## What is Expression Evaluation?
Expression evaluation using a stack is a classic application in Data Structures. 

## **Algorithm to Evaluate Postfix Expression:**
1.Scan expression left to right.

2.If operand, push onto stack.

3.If operator, pop 2 operands, apply operation, and push result back.

---

## Example
- Postfix: 5 6 2 + * 12 4 / -
Step 1: Push 5
Step 2: Push 6
Step 3: Push 2
Step 4: '+' → pop 2 and 6 → 6+2=8 → push 8
Step 5: '*' → pop 8 and 5 → 5*8=40 → push 40
Step 6: Push 12
Step 7: Push 4
Step 8: '/' → 12/4 = 3 → push 3
Step 9: '-' → 40-3 = 37 → push 37
Final Result: 37


After all tokens, the result is the top of the stack.
