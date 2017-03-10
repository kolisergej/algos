#ifndef MY_QUEUE_H
#define MY_QUEUE_H

#include <stack>

using std::stack;


/// @brief Queue implementation based on two stacks
/// Get element complexity is amortized O(1)
template<class Type>
class my_queue {
    std::stack<Type> m_first;
    std::stack<Type> m_second;

public:
    bool empty() const {
        return m_first.empty() && m_second.empty();
    }

    typename std::stack<Type>::size_type size() const {
        return m_first.size() + m_second.size();
    }

    void push_back(const Type& item) {
        m_first.push(item);
    }

    Type pop_front() {
        if (m_first.empty() && m_second.empty()) {
            throw std::runtime_error("Queue is empty");
        }
        if (m_second.empty()) {
            while (!m_first.empty()) {
                m_second.push(m_first.top());
                m_first.pop();
            }
        }
        const Type item = m_second.top();
        m_second.pop();
        return item;
    }
};

#endif // MY_QUEUE_H
