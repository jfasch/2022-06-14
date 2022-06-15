#include <optional>
#include <iostream>
#include <atomic>

using namespace std;

int main()
{
    auto x = atomic<optional<int>>();
    if (x)
        cout << "has not been set" << endl;
    x = 42;
    if (x)
        cout << "has been set to " << x << endl;
    return 0;
}
