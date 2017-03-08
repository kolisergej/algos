#ifndef INTERVAL_MAP
#define INTERVAL_MAP

#include <climits>
#include <map>

using std::map;

// Template class for IntervalMap container
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
        if (intervalFirst >= intervalSecond) {
            return;
        }

        auto startIt = m_intervalMap.upper_bound(intervalFirst);
        auto finishIt = m_intervalMap.upper_bound(intervalSecond);
        const ValueType previousValue = (--finishIt)->second;
        finishIt++;
        auto insertedFirst = m_intervalMap.insert(startIt, std::make_pair(intervalFirst, value));
        auto insertedSecond = m_intervalMap.insert(finishIt, std::make_pair(intervalSecond, previousValue));

        m_intervalMap.erase(++insertedFirst, insertedSecond);
    }

    void show() {
        for (auto p: m_intervalMap) {
            cout << p.first << " " << p.second << std::endl;
        }
    }
};

#endif // INTERVAL_MAP

