
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> history;

    history.push("google.com");
    history.push("youtube.com");
    history.push("abcsc.com");
    history.push("facebook.com");

    // Press Back twice
    history.pop();
    history.pop();

    cout << "Current page: " << history.top();

    return 0;
}
