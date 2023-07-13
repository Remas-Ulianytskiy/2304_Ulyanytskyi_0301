#include <iostream>
#include <deque>

using namespace std;

int main()
{
    const unsigned DEQUE_MAX_SIZE = 48;
    const deque<int64_t> SEQUENCE = { -13, 0, 10, -4, 6, 11, 12, 28, 50, 89, 166, 304 };
    deque<int64_t> sequence = SEQUENCE;

    while (sequence.size() < DEQUE_MAX_SIZE)
    {
        int size = sequence.size();
        int64_t preceding_element = sequence[2] - sequence[1] - sequence[0] + 1;
        int64_t next_element = sequence[size-3] + sequence[size-2] + sequence[size-1] - 1;

        sequence.push_back(next_element);
        sequence.push_front(preceding_element);
    }

    cout << "\n\ndeque size: " << sequence.size() << endl;
    cout << "Deque elements:";
    for (int i = 0; i < sequence.size(); ++i)
    {
        if (i % 10 == 0)
            cout << endl;
        cout << sequence[i] << ' ';
    }    

    return 0;
}