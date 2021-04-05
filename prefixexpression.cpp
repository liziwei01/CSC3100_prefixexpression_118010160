#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

int invalidInput = 0;

class StringStack {

public:

   StringStack(int stackCapacity);

   ~StringStack();

   int size();

   bool isEmpty();

   void clear();

   void push(string ch);

   string pop();

   string peek();


   string *array;
   int capacity;
   int count;
};

StringStack::StringStack(int stackCapacity) {
   capacity = stackCapacity;
   array = new string[capacity];
   count = 0;
}

StringStack::~StringStack() {
   delete[] array;
}

int StringStack::size() {
   return count;
}

bool StringStack::isEmpty() {
   return count == 0;
}

void StringStack::clear() {
   count = 0;
}

void StringStack::push(string s) {
    array[count++] = s;
}

string StringStack::pop() {
   if (isEmpty()) {
       invalidInput = 1;
    }
    return array[--count];
}

string StringStack::peek() {
  if (isEmpty()) {
      invalidInput = 1;
    }
    return array[count - 1];
}

long long mod107(long long i) {
    while (true) {
        if (i>=0) {
            return i % 1000000007;
        } else {
            i = i + 1000000007;
        }
    }
}

int main() {
    int N;
    cin >> N;
    StringStack stack1(N);
    StringStack stack2(N);
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        stack1.push(str);
    }

    for (int j = 0; j < N; j++) {
        string c = stack1.pop();
        if (isdigit(c.c_str()[0])) {
            stack2.push(c);
        } else {
            if (stack2.count >= 2) {
                long long number1 = mod107(stoll(stack2.pop()));
                long long number2 = mod107(stoll(stack2.pop()));
                if (c == "+") {
                    stack2.push(to_string(mod107(number1 + number2)));
                } else if (c == "-") {
                    stack2.push(to_string(mod107(number1 - number2)));
                } else if (c == "*") {
                    stack2.push(to_string(mod107(number1 * number2)));
                } else {
                    invalidInput = 1;
                }
            } else {
                invalidInput = 1;
                break;
            }
        }
    }

    long long result;

    //two faults
    //the first one: left no numbers
    if (stack2.isEmpty()) {
        invalidInput = 1;
    } else {
        result = stoll(stack2.pop());
    }

    //the second one: left some more numbers
    if (!stack2.isEmpty()) {
        invalidInput = 1;
    }

    //cout
    if (!invalidInput) {
        cout << result;
    } else {
        cout << "Invalid";
    }

    return 0;
}
