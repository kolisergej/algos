#ifndef INTERVAL_MAP
#define INTERVAL_MAP

#include <climits>
#include <map>

using std::map;

template<class ValueType>
class IntervalMap {
    map<int, ValueType> m_intervalMap;

public:
    explicit IntervalMap(const ValueType& value) {
        m_intervalMap[std::numeric_limits<int>::min()] = value;
    }

    typename map<int, ValueType>::size_type size() const {
        return m_intervalMap.size();
    }


    ValueType getElement(int key) {
        return (--m_intervalMap.upper_bound(key))->second;
    }

    void setElement(int intervalFirst, int intervalSecond, const ValueType& value) {
        if (intervalFirst > intervalSecond) {
            return;
        }

        auto startIt = m_intervalMap.upper_bound(intervalFirst);
        const ValueType previousValue = *(startIt - 1);
        auto finishIt = m_intervalMap.upper_bound(intervalSecond);
        m_intervalMap.erase(startIt, finishIt);

        m_intervalMap.insert(startIt, value);
        m_intervalMap.insert(finishIt + 1, previousValue);
    }
};

#endif // INTERVAL_MAP

